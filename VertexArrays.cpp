// VertexArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    std::cout << "Hello World!\n";
    RenderWindow window(VideoMode(1980 , 1080), "Vertex Arrays");

    /* **************View********************/
    //View view(FloatRect(900,0,500, 400));//zoom in the coordinates of sun in the background
    View view(FloatRect(30, 500, 400, 300));//zoom in the coordinates of sun in the background
    view.rotate(45);
    window.setView(view);
    Sprite background;
    Texture texture_view;
    if (!texture_view.loadFromFile("background.png"))
    {
        std::cout << "could not load image!!";
    }
    background.setTexture(texture_view);
    /***********************************************/
    sf::Vertex point;
    point.position = sf::Vector2f(300,300);
    point.color = Color::Red;

    VertexArray line(Lines, 2);
    line[0].position = Vector2f(500,500);
    line[1].position = Vector2f(500,600);

    line[0].color = Color::Yellow;
    line[1].color = Color::Cyan;

    VertexArray triangle(Triangles, 3);
    triangle[0].position= Vector2f(300, 400);
    triangle[0].color = Color::Cyan;
    triangle[1].position = Vector2f(400,520 );
    triangle[1].color = Color::Magenta;
    triangle[2].position = Vector2f(350, 520);
    triangle[2].color = Color::Green;

    VertexArray quad(Quads, 4);
    quad[0].position = Vector2f(900, 100);
    quad[0].color = Color::Red;
    quad[1].position = Vector2f(1100, 100);
    quad[1].color = Color::Red;
    quad[2].position = Vector2f(1100, 250);
    quad[2].color = Color::Red;
    quad[3].position = Vector2f(900, 250);
    quad[3].color = Color::Red;

    /*Transformation of Vertex Array*/
    Transform transform;
    
    transform.rotate(45, Vector2f(200, 150));

   
    /*How to use texture coordinates. and incorporate a texture into the quad. image file log.png is loaded into the texture */
    Texture texture;
    if (!texture.loadFromFile("log.png"))
        std::cout << "Couldnt load file";
    quad[0].texCoords = Vector2f(0, 0);
    quad[1].texCoords = Vector2f(300, 0);
    quad[2].texCoords = Vector2f(300, 150);
    quad[3].texCoords = Vector2f(0, 150);
    
    //Draw a triangle using linestrip, each line starts from the ending point of the previous line. 
    VertexArray ls(LinesStrip, 4);
    ls[0].position = Vector2f(500,100);
    ls[0].color = Color::Red;

    ls[1].position = Vector2f(800, 500);
    ls[1].color = Color::Yellow;

    ls[2].position = Vector2f(200, 50);
    ls[2].color = Color::Red;

    ls[3].position = Vector2f(500, 100);
    ls[3].color = Color::Red;

    //
    VertexArray ts(TriangleStrip, 4);
    ts[0].position = Vector2f(600, 600);
    ts[0].color = Color::Red;

    ts[1].position = Vector2f(400, 900);
    ts[1].color = Color::Red;

    ts[2].position = Vector2f(800, 900);
    ts[2].color = Color::Red;

    ts[3].position = Vector2f(850, 950);
    ts[3].color = Color::Yellow;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close(); break;
                
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(line);
            window.draw(triangle);
            window.draw(quad,&texture);
            window.draw(triangle, transform);
            window.draw(ls);
            window.draw(ts);
            
            
            window.display();
        }
        
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
