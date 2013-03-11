//
//  Controller.h
//  Physical.Simulation.Tool
//
//  Created by Silvio Fragnani on 14/07/12.
//  
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ctime>

#include "library.graphic/LibraryGraphic.h"
#include "physics.engine/PhysicsEngine.h"
#include "common/Commons.h"

//!Class of centralizing all actions coming from the interface
class Controller {
private:
    MainEngine * mainEngine;
    MainGraphic * mainGraphic;
    
    SimulatedObject * objectEdition;
    SimulatedObject * objectOffset;

    TypeObject typeNextObject;

    bool editMode;
    //! static controller (singleton)
    static Controller * controller;

public:
    Controller();
    ~Controller();
    
    void initializeContextOpenGLES();
    void initializeEngine();

    void loadSceneFromFile(std::string _charContentFile);
    std::string generateSimulationToCharacter();
    void generateRandonSimulation(unsigned _numberObjects);

    void resizeScreen(real _width, real _height);
    
    void updateInformation(real _duration);
    void draw();
    void stopSimulation();
    void startSimulation();
    void editSimulation();
    void clearSimularion();
    bool isRunning();
    bool isInitialized();
    
    void createSimulatedObject2D(TypeObject _typeObject);
    void createSimulatedObject3D(TypeObject _typeObject);
    void addAndInitSimulatedObject3D(SimulatedObject * _simulatedObject, const Vector3 &_gravity=Vector3(0.0f, -9.8f, 0.0f));
    void updateSimulatecObject(SimulatedObject * _simulatedObject, const Vector3 &_gravity);
    SimulatedObject * makeSimulatedObject3D();
    SimulatedObject * makeSimulatedObject3D(TypeObject _typeObject);
    void deleteSimulatedObject(SimulatedObject * _simulatedObject);

    void setTypeNextObject(TypeObject _typeObject);
    TypeObject getTypeNextObject();

    bool alreadyExistPlan();
    SimulatedObject * getExistingPlan();
    
    void touchesMoved(real _x, real _y, int _countFingers);
    void touchesBegan(real _x, real _y);
    void touchesEnded(real _x, real _y);
    void touchesCancelled(real _x, real _y);
    void longPressDetected(real _x, real _y);
    void pinchDetected(real _scale, real _velocity, bool _began);
    void rotationDetected(real _radians, real _velocity, bool _began);
    void doubleTapOneFingerDetected(real _x, real _y);
    void oneTapThreeFingerDetected(real _x, real _y);
    void swipeRightDetected(real _x, real _y);
    void swipeLeftDetected(real _x, real _y);

    bool isEditMode();
    void setEditMode(bool _editMode);

    std::vector<SimulatedObject *> * getSimulatedObjects();

    static Controller * getInstance();
    static void destroy();
};

#endif
