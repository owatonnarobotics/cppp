// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>

#include "swerve/src/include/SwerveTrain.h"
#include "controller/Controller.h"
#include "navX/NavX.h"
#include "limelight/Limelight.h"

frc::Joystick* playerOne;

void Robot::RobotInit() {

    playerOne = new frc::Joystick(R_controllerPortPlayerOne);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {

    SwerveTrain::GetInstance().SetZeroPosition();
    SwerveTrain::GetInstance().SetSwerveBrake(true);
}

void Robot::TeleopPeriodic() {

    SwerveTrain::GetInstance().WaitASecond();
    NavX::GetInstance().resetYaw();
    
    // Put your code here

    SwerveTrain::GetInstance().AssumeZeroPositionForever();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {

    SwerveTrain::GetInstance().SetSwerveBrake(false);
    SwerveTrain::GetInstance().SetDriveBrake(true);
}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif
