//fc.h
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class fc{
private :
    char cndVar[40][40];
    char varList[37][25], /* variable list*/ clVarList[1445][25]; /* clause var list */
    char c[30] /* condition variable */,  v[3]; /*variable */
    char OIL_PUMP[4],OIL_FILTER[4],OIL[4],OIL_DRAIN_PLUG[4],ENGINE_GASKET[4],RADIATOR[4],RADIATOR_HOSE[4],
            TRANSMISSION_DRAIN_PLUG[4],BATTERY[4],IGNITION_SWITCH[4],STARTER_MOTOR[4],BATTERY_TERMINALS[4],FUEL_LEVEL[4],
            FUEL_CONDITION[4],FUEL_SYSTEM[4],VACUUM_HOSE[4],SPARK_PLUGS[4],FUEL_INJECTORS[4],IGNITION_WIRES[4],ENGINE_COMPONENTS[4]
    ,ALTERNATOR[4],ALTERNATOR_BELT[4],BATTERY_WIRES[4],ELECTRICAL_SYSTEM[4],COOLANT[4],DRIVE_BELT[4],RADIATOR_FAN[4],
            WATER_PUMP[4],TIRE_PRESSURE[4],AIR_FILTER[4],FUEL_TANK[4],FUEL_MANAGEMENT_SYSTEM[4],BRAKE_PARTS[4],BRAKE_LINES[4],
            REPLACE[4],RECONNECT[4];
    int instList[17];         /* instantiated list*/
    int flag, i, j, k, s, fp   /* front pointer */;
    int  bp  /* back pointer */, sn; /* statement number */
    int cn;  /* clause number */
    char end[4];

    void searchClauses();
    void check_instantiation();
    void instantiate();
    void fcLoop();

public:
    fc(string);
    char * start();
};
