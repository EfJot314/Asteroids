//colors
#include "colors.h"
//fonts
#include "fonts.h"


//real_distance = pixel_distance * scaler
#define scaler 5.0f
//time between two frames
#define deltaTime 0.5f
//size of default objects
#define defaultSize 50.0f
//time, when player is untouchable after hit (in seconds)
#define playerUntouchableTime 2.0f
//number of blinks, when player is untouchable
#define playerNoBlinks 6
//acceleration of a player
#define playerAcceleration 0.50f
//max player speed
#define playerMaxSpeed 50.0f
//rotation speed of a player
#define playerRotationSpeed 4.0f
//length of a player
#define playerLen 130.0f
//margin for generating asteroids
#define asteroidMargin 200
//min asteroid velocity
#define asteroidVelocityMin 10.0f
//max asteroid velocity
#define asteroidVelocityMax 30.0f
//number of points in asteroid shape
#define asteroidShapeN 10
//asteroid basic radius
#define asteroidRadius 130
//small asteroid radius multiplayer
#define asteroidSmallRadius 0.5f
//max asteroid shape delta
#define asteroidMaxFactor 0.3f
//max asteroid rotation speed
#define asteroidMaxRotationSpeed 15
//number of small asteroids created by explosions
#define asteroidMinExplosionNumer 0
#define asteroidMaxExplosionNumer 4
//asteroid line thickness
#define asteroidLineThickness 5.0f
//bullet velocity
#define bulletVelocity 60.0f
//bullet size
#define bulletSize 50.0f
//bullet width factor
#define bulletWidthFactor 0.15f
//time between shoots (in seconds)
#define bulletDelay 0.2f
//max bullet distance
#define bulletMaxDistance 1900.0f
//max fire angle
#define fireMaxAngleDeg 20
//fire size
#define fireSize 40.0f
//fire velocity
#define fireVelocity 10.0f
//fire existing time (in seconds)
#define fireDuration 1.0f
//time between fire creations (in seconds)
#define fireDelay 0.15f
//size of heart
#define heartSize 6.0f
//heart line thickness
#define heartLineThickness 2.0f
//default margin around heart(s)
#define heartsMargin 25.0f
//button background colors
#define buttonDefaultBaseColor TRANSPARENT
#define buttonDefaultHoverColor DARK_GRAY
//button dimensions
#define buttonDefaultWidthRatio 0.5f
#define buttonDefaultHeightPx 60
