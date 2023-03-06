//bc.h
#include <string>

using namespace std;

class bc{
private :
    /*****backward chaining *******/
    char concList[40][5]; /*  conclusion list */
    char varList[45][17]; /*  variable list */
    char clVarList[1716][17]; /*  clause variable list */
    char varble[45];
    char PART[4],PROBLEM[4],OIL_PRESSURE[4],OIL_FILTER[4],OIL_GRADE[4],LEAK[4],OIL_LEAK[4],COOLANT_LEAK[4],
            TRANS_LEAK[4],OIL_DRAIN_PLUG[4],ENGINE_LEAK[4],RADIATOR_LEAK[4],RADIATOR_HOSE[4],TRANS_DRAIN_PLUG[4],
            ENGINE_ROTATES[4],BATT_TERMINALS[4],FUEL[4],START_MOTOR[4],ROUGH[4],VACUUM_HOSE[4],SPARK_PLUGS[4],
            BAD_FUEL[4],FUEL_INJECTORS[4],IGNITION_WIRES[4],KNOCKING[4],BATT_CHARGE[4],BATT_TEST[4],ALTERNATOR[4],
            ALT_DRIVE_BELT[4],BATT_WIRES[4],OVERHEAT[4],COOLANT[4],DRIVE_BELT[4],RADIATOR[4],RADIATOR_FAN[4],FUEL_USE[4],
            TIRE_PRESSURE[4],AIR_FILTER[4],FUEL_SMELL[4],CHECK_BRAKE[4],WOBBLE[4],CHEMICAL_SMELL[4],SPONGEY[4],
            SQUEAK[4], end[4];
    char buff[128];

    int instList[45]; /* instantiated list */

    int stateStk[45]; /* statement stack */
    int clausStk[45] /* clause stack */, stateNum, flag, i, j, s, k, sp /*stack pointer */;
    float BATT_VOLTAGE;
    void determine_member_concl_list();
    void push_on_stack();
    void instantiate();
    void chkClauses();
    void bcLoop();
    void popStack();
    char yourproblem();

public :
    char * start();
    bc(){}
};
