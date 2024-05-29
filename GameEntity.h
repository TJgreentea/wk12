#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include<tuple>
class GameEntity{
protected: std::tuple<int,int>position;
char type;
public: 
GameEntity(int x,int y,char type);
std::tuple<int,int> getPos();
char getType();

};
#endif