#include <controllers/PlayerController.hpp>
#include <SFML/Window/Keyboard.hpp>

PlayerController::PlayerController(int id, int eID, tgd::System& mSystem, tmx::MapLoader* mapLoader)
: Controller(id, eID)
, mMoveVector()
, mSprite(nullptr)
, mMapPtr(mapLoader)
, mColFlag(-1)
{
    retrieveProperties(eID, mSystem);
    mMoveVector = sf::Vector2f(0,0);

    //setup collision points
    collisionPoints[0] = sf::Vector2f(-30, -30); //top left
    collisionPoints[1] = sf::Vector2f( 30, -30); //top right
    collisionPoints[2] = sf::Vector2f(-30,  30); //bottom left
    collisionPoints[3] = sf::Vector2f( 30,  30); //bottom right
}

PlayerController::~PlayerController()
{
    delete mSprite;
    delete mMapPtr;
}

void PlayerController::update(sf::Time dt)
{

    handleRealtimeInput();

    mColFlag = checkCollisions();

    //std::cout << "Col Flag: " << mColFlag << std::endl;

    setVelocity(mMoveVector, dt);
}

void PlayerController::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void PlayerController::handleRealtimeInput()
{
    mMoveVector = sf::Vector2f(0,0);



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(mColFlag != 0 && mColFlag != 1)
        {
            mMoveVector.y += -200;
        }

        //temp sprite change code


    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(mColFlag != 2 && mColFlag != 3)
        {
            mMoveVector.y += 200;
        }



    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(mColFlag != 1 && mColFlag != 3)
        {
            mMoveVector.x += 200;
        }


    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(mColFlag != 0 && mColFlag != 2)
        {
            mMoveVector.x += -200;
        }



    }

}

int PlayerController::checkCollisions()
{
    //this currently only checks collisions with the map
    std::vector<tmx::MapObject*> objects = mMapPtr->QueryQuadTree(mSprite->getGlobalBounds());
    //std::cout << "Objects on screen: " << objects.size() << std::endl;
    for(int i = 0; i<objects.size(); i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(objects[i]->Contains(mSprite->getPosition() + collisionPoints[j]))
            {
                //std::cout<<"Collision Detected" << std::endl;
                return j;
                break;
            }
        }
    }
    return -1;
}

int PlayerController::getRequirements()
{

    //this will return the requirements for the controller
    return 0;
}

void PlayerController::retrieveProperties(int eID, tgd::System& system)
{
    std::shared_ptr<tgd::Entity> tempEnt;
    tempEnt = system.fetchEntity(eID);
    auto sprPtr = std::dynamic_pointer_cast<tgd::Property<sf::Sprite>>(tempEnt->accessProperty(Properties::Visible));
    mSprite = sprPtr->getValue();
}

int PlayerController::getID()
{
    return Controller::getID();
}

int PlayerController::getEntityID()
{
    return Controller::getEntityID();
}

void PlayerController::setVelocity(sf::Vector2f moveVector, sf::Time dt)
{

    mSprite->move(moveVector * dt.asSeconds());

}
