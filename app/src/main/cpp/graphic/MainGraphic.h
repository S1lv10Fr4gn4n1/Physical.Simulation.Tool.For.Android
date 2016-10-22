//
//  MainGraphic.h
//  Physical.Simulation.Tool
//
//  Created by Silvio Fragnani da Silva on 12/06/12.
//  
//

#ifndef MAINGRAPHIC_H
#define MAINGRAPHIC_H

#include <vector>

#include "Shader.h"
#include "common/Commons.h"
#include "log.h"

//!Class responsible for drawing the SimulatedObject in simulation
class MainGraphic {
    Shader * shader;
    SimulatedObject * simulatedObjectDrawn;
    
    void initializeShader();
public:
    MainGraphic();
    ~MainGraphic();
    
    Shader * getShader();
    void draw(World * _world);
};

#endif
