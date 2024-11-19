#include "duck_state_planning.h"

struct PlanningStateConfig {
    DuckStateType id = DuckStateType::IS_PLANING; 
    std::string name = "Planning"; 
};
PlanningStateConfig planning_config;

DuckStatePlanning::DuckStatePlanning():DuckState(planning_config.id, planning_config.name){}
void DuckStatePlanning::update(Player& player) {
    (void)player;
    
} 
DuckStatePlanning::~DuckStatePlanning() {}