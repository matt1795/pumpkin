// Feedback Control System
//
// Author: Matthew Knight
// File Name: feedback-control.hpp
// Date: 2018-11-25
//
// This is another composition type class which specifically arranges subsystems
// to create a feeback control architecture. Note that while most diagrams have
// the controller operate on an error signal, our controller will take in both
// the reference and measured signals for non-linear controllers down the road
// -- linear controllers will be able to calculate error on their own.

#include "feedback-control.hpp"

#include <utility>

