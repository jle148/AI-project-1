//fc.cpp
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>

#include "fc.h"

using namespace std;

fc::fc(string problem) {
    strcpy(cndVar[1], problem.c_str());
}


char * fc::start() {
    /******** INITIALIZATION SECTION ***********/
    fp = 1;
    bp = 1;

    for (i = 1; i < 1445; i++)
        strcpy(clVarList[i], "");
    for (i = 2; i < 40; i++)
        strcpy(cndVar[i], "");
    for (i = 1; i < 37; i++)
        strcpy(varList[i], "");
    for (i = 1; i < 17; i++) {
        instList[i] = 0;
    }

    strcpy(varList[1], "OIL_PUMP");
    strcpy(varList[2], "OIL_FILTER");
    strcpy(varList[3], "OIL");
    strcpy(varList[4], "OIL_DRAIN_PLUG");
    strcpy(varList[5], "ENGINE_GASKET");
    strcpy(varList[6], "RADIATOR");
    strcpy(varList[7], "RADIATOR_HOSE");
    strcpy(varList[8], "TRANSMISSION_DRAIN_PLUG");
    strcpy(varList[9], "BATTERY");
    strcpy(varList[10], "IGNITION_SWITCH");
    strcpy(varList[11], "STARTER_MOTOR");
    strcpy(varList[12], "BATTERY_TERMINALS");
    strcpy(varList[13], "FUEL_LEVEL");
    strcpy(varList[14], "FUEL_CONDITION");
    strcpy(varList[15], "FUEL_SYSTEM");
    strcpy(varList[16], "VACUUM_HOSE");
    strcpy(varList[17], "SPARK_PLUGS");
    strcpy(varList[18], "FUEL_INJECTORS");
    strcpy(varList[19], "IGNITION_WIRES");
    strcpy(varList[20], "ENGINE_COMPONENTS");
    strcpy(varList[21], "ALTERNATOR");
    strcpy(varList[22], "ALTERNATOR_BELT");
    strcpy(varList[23], "BATTERY_WIRES");
    strcpy(varList[24], "ELECTRICAL_SYSTEM");
    strcpy(varList[25], "COOLANT");
    strcpy(varList[26], "DRIVE_BELT");
    strcpy(varList[27], "RADIATOR_FAN");
    strcpy(varList[28], "WATER_PUMP");
    strcpy(varList[29], "TIRE_PRESSURE");
    strcpy(varList[30], "AIR_FILTER");
    strcpy(varList[31], "FUEL_TANK");
    strcpy(varList[32], "FUEL_MANAGEMENT_SYSTEM");
    strcpy(varList[33], "BRAKE_PARTS");
    strcpy(varList[34], "BRAKE_LINES");
    strcpy(varList[35], "REPLACE");
    strcpy(varList[36], "RECONNECT");

    printf("*** VARIABLE LIST ***\n");
    for (i = 1; i < 37; i++)
        printf("ENTER VARIABLE   %d   %s\n", i, varList[i]);
    printf("HIT RETURN TO CONTINUE");
    getchar();

    printf("*** CLAUSE-VARIABLE LIST ***\n");
    strcpy(clVarList[1], "OIL_PUMP");
    strcpy(clVarList[39], "OIL_FILTER");
    strcpy(clVarList[77], "OIL");
    strcpy(clVarList[115], "OIL_DRAIN_PLUG");
    strcpy(clVarList[153], "ENGINE_GASKET");
    strcpy(clVarList[191], "RADIATOR");
    strcpy(clVarList[229], "RADIATOR_HOSE");
    strcpy(clVarList[267], "TRANSMISSION_DRAIN_PLUG");
    strcpy(clVarList[305], "BATTERY");
    strcpy(clVarList[343], "IGNITION_SWITCH");
    strcpy(clVarList[381], "STARTER_MOTOR");
    strcpy(clVarList[419], "BATTERY_TERMINALS");
    strcpy(clVarList[457], "FUEL_LEVEL");
    strcpy(clVarList[495], "FUEL_CONDITION");
    strcpy(clVarList[533], "FUEL_SYSTEM");
    strcpy(clVarList[571], "VACUUM_HOSE");
    strcpy(clVarList[609], "SPARK_PLUGS");
    strcpy(clVarList[647], "FUEL_INJECTORS");
    strcpy(clVarList[685], "IGNITION_WIRES");
    strcpy(clVarList[723], "ENGINE_COMPONENTS");
    strcpy(clVarList[761], "BATTERY");
    strcpy(clVarList[799], "ALTERNATOR");
    strcpy(clVarList[837], "ALTERNATOR_BELT");
    strcpy(clVarList[875], "BATTERY_WIRES");
    strcpy(clVarList[913], "ELECTRICAL_SYSTEM");
    strcpy(clVarList[951], "COOLANT");
    strcpy(clVarList[989], "DRIVE_BELT");
    strcpy(clVarList[1027], "RADIATOR");
    strcpy(clVarList[1065], "RADIATOR_FAN");
    strcpy(clVarList[1103], "WATER_PUMP");
    strcpy(clVarList[1141], "TIRE_PRESSURE");
    strcpy(clVarList[1179], "AIR_FILTER");
    strcpy(clVarList[1217], "FUEL_TANK");
    strcpy(clVarList[1255], "FUEL_MANAGEMENT_SYSTEM");
    strcpy(clVarList[1293], "BRAKE_PARTS");
    strcpy(clVarList[1331], "BRAKE_PARTS");
    strcpy(clVarList[1369], "BRAKE_LINES");
    strcpy(clVarList[1407], "BRAKE_PARTS");

    for (i = 1; i < 38; i++) {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 38; j++) {
            k = 38 * (i - 1) + j;
            printf("VARIABLE %d  %s\n", j, clVarList[k]);
        }
    }

    /****** INFERENCE SECTION *****************/
        /* move backpointer (bp) to back */
    bp = bp + 1;
    /* set the condition variable pointer consisting of the
    statement number (sn) and the clause number (cn) */
    sn = 1;
    cn = 1;
    /* find the next statement number containing the condition variable
    which is in front of the queue (cndVar), this statement number
    is located in the clause variable list (clVarList) */
    /* start at the beginning */
    flag = 1;
    fcLoop();
    return end;
}

void fc::fcLoop(){
    bool exit = false;
    while(! exit) {
        searchClauses(); //return with a statement number
        cn = 1; /* point to first clause in statement */
        if (sn != 0)
        {
            i = 38 * (sn - 1) + cn; /* locate the clause */
            strcpy(v, clVarList[i]); /* clause variable */

            while (strcmp(v, "") != 0) /* more clauses */
            {
                /* check instantiation of this clause */
                check_instantiation();
                cn = cn + 1;
                /* check next clause */
                i = 38 * (sn - 1) + cn;
                strcpy(v, clVarList[i]);
            }

            /* no more clauses - check IF part of statement */
            s = 0;
            /* sample IF-THEN statements from the position knowledge base */
            switch (sn) {
                case 1:
                    if (strcmp(OIL_PUMP, "BAD") == 0) s = 1;
                    break;
                case 2:
                    if (strcmp(OIL_FILTER, "BAD") == 0) s = 1;
                    break;
                case 3:
                    if (strcmp(OIL, "BAD") == 0) s = 1;
                    break;
                case 4:
                    if (strcmp(OIL_DRAIN_PLUG, "BAD") == 0) s = 1;
                    break;
                case 5:
                    if (strcmp(ENGINE_GASKET, "BAD") == 0)s = 1;
                    break;
                case 6:
                    if (strcmp(RADIATOR, "BAD") == 0) s = 1;
                    break;
                case 7:
                    if (strcmp(RADIATOR_HOSE, "BAD") == 0) s = 1;
                    break;
                case 8:
                    if (strcmp(TRANSMISSION_DRAIN_PLUG, "BAD") == 0) s = 1;
                    break;
                case 9:
                    if (strcmp(BATTERY, "BAD") == 0) s = 1;
                    break;
                case 10:
                    if (strcmp(IGNITION_SWITCH, "BAD") == 0) s = 1;
                    break;
                case 11:
                    if (strcmp(STARTER_MOTOR, "BAD") == 0) s = 1;
                    break;
                case 12:
                    if (strcmp(BATTERY_TERMINALS, "BAD") == 0) s = 1;
                    break;
                case 13:
                    if (strcmp(FUEL_LEVEL, "BAD") == 0) s = 1;
                    break;
                case 14:
                    if (strcmp(FUEL_CONDITION, "BAD") == 0) s = 1;
                    break;
                case 15:
                    if (strcmp(FUEL_SYSTEM, "BAD") == 0) s = 1;
                    break;
                case 16:
                    if (strcmp(VACUUM_HOSE, "BAD") == 0) s = 1;
                    break;
                case 17:
                    if (strcmp(SPARK_PLUGS, "BAD") == 0) s = 1;
                    break;
                case 18:
                    if (strcmp(FUEL_INJECTORS, "BAD") == 0) s = 1;
                    break;
                case 19:
                    if (strcmp(IGNITION_WIRES, "BAD") == 0) s = 1;
                    break;
                case 20:
                    if (strcmp(ENGINE_COMPONENTS, "BAD") == 0) s = 1;
                    break;
                case 21:
                    if (strcmp(BATTERY, "BAD") == 0) s = 1;
                    break;
                case 22:
                    if (strcmp(ALTERNATOR, "BAD") == 0) s = 1;
                    break;
                case 23:
                    if (strcmp(ALTERNATOR_BELT, "BAD") == 0) s = 1;
                    break;
                case 24:
                    if (strcmp(BATTERY_WIRES, "BAD") == 0) s = 1;
                    break;
                case 25:
                    if (strcmp(ELECTRICAL_SYSTEM, "BAD") == 0) s = 1;
                    break;
                case 26:
                    if (strcmp(COOLANT, "BAD") == 0) s = 1;
                    break;
                case 27:
                    if (strcmp(DRIVE_BELT, "BAD") == 0) s = 1;
                    break;
                case 28:
                    if (strcmp(RADIATOR_FAN, "BAD") == 0) s = 1;
                    break;
                case 29:
                    if (strcmp(WATER_PUMP, "BAD") == 0) s = 1;
                    break;
                case 30:
                    if (strcmp(TIRE_PRESSURE, "BAD") == 0) s = 1;
                    break;
                case 31:
                    if (strcmp(AIR_FILTER, "BAD") == 0) s = 1;
                    break;
                case 32:
                    if (strcmp(FUEL_TANK, "BAD") == 0) s = 1;
                    break;
                case 33:
                    if (strcmp(FUEL_MANAGEMENT_SYSTEM, "BAD") == 0) s = 1;
                    break;
                case 34:
                    if (strcmp(BRAKE_PARTS, "BAD") == 0) s = 1;
                    break;
                case 35:
                    if (strcmp(BRAKE_LINES, "BAD") == 0) s = 1;
                    break;
            }


            /* see if the THEN part should be inovked, i.e., s=1 */
            if (s != 1) {
                flag = sn + 1;
                fcLoop();
                continue;
            }
            else {
                exit = true;
            }
            /* invoke THEN part */
            switch (sn) {

                /* put variable on the conclusion variable queue */
                case 1:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 2:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 3:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 4:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 5:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 6:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 7:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 8:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 9:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 10:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 11:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 12:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 13:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 14:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 15:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 16:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 17:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 18:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 19:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 20:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 21:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 22:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 23:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 24:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 25:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 26:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 27:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 28:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 29:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 30:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 31:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 32:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 33:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 34:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 35:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 36:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
                case 37:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;

                case 38:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    strcpy(end, "Replace");
                    instantiate();
                    break;
            }
        }
        fp = fp + 1;
        if (fp < bp) {
            /* check out the condition variable */
            flag = 1;
            fcLoop();
            continue;
        }
        return;
    }
}
/* no more conclusion variables on queue */

//==========================================================================
/* Routine to instantiate a variable (v) if it isn't already.
The instantiate indication (instList) is a 0 if not, a 1 if it is.
The vriable list (varList) contains the variable (v) */

void fc::check_instantiation()
{
    i=1;

    /* find variable in the variable list */
    while ((strcmp(v, varList[i]) != 0) && (i <= 37)) i = i+1;

    /* check if already instantiated */
    if (instList[i] != 1)
    {
        instList[i] = 1; /* mark instantiated */

        switch (i)
        {
            /* input statements for sample position knowledge base */
            case 1:
                printf("Is the Oil pump GOOD OR BAD?");
                std::cin >> OIL_PUMP;
                break;
            case 2:
                printf("Is the Oil filter GOOD OR BAD?");
                std::cin >> OIL_FILTER;
                break;
            case 3:
                printf("Is the Oil GOOD OR BAD?");
                std::cin >> OIL;
                break;
            case 4:
                printf("Is the Oil drain plug GOOD OR BAD?");
                std::cin >> OIL_DRAIN_PLUG;
                break;
            case 5:
                printf("Is the engine gasket GOOD OR BAD?");
                std::cin >> ENGINE_GASKET;
                break;
            case 6:
                printf("Is the radiator GOOD OR BAD?");
                std::cin >> RADIATOR;
                break;
            case 7:
                printf("Is the radiator hose GOOD OR BAD?");
                std::cin >> RADIATOR_HOSE;
                break;
            case 8:
                printf("Is the transmission drain plug GOOD OR BAD?");
                std::cin >> TRANSMISSION_DRAIN_PLUG;
                break;
            case 9:
                printf("Is the battery GOOD OR BAD?");
                std::cin >> BATTERY;
                break;
            case 10:
                printf("Is the ignition switch GOOD OR BAD?");
                std::cin >> IGNITION_SWITCH;
                break;
            case 11:
                printf("Is the starter motor GOOD OR BAD?");
                std::cin >> STARTER_MOTOR;
                break;
            case 12:
                printf("Is the battery terminals GOOD OR BAD?");
                std::cin >> BATTERY_TERMINALS;
                break;
            case 13:
                printf("Is the fuel level GOOD OR BAD?");
                std::cin >> FUEL_LEVEL;
                break;
            case 14:
                printf("Is the fuel condition GOOD OR BAD?");
                std::cin >> FUEL_CONDITION;
                break;
            case 15:
                printf("Is the fuel system GOOD OR BAD?");
                std::cin >> FUEL_SYSTEM;
                break;
            case 16:
                printf("Is the vacuum hose GOOD OR BAD?");
                std::cin >> VACUUM_HOSE;
                break;
            case 17:
                printf("Is the spark plugs GOOD OR BAD?");
                std::cin >> SPARK_PLUGS;
                break;
            case 18:
                printf("Is the fuel injectors GOOD OR BAD?");
                std::cin >> FUEL_INJECTORS;
                break;
            case 19:
                printf("Is the ignition wires GOOD OR BAD?");
                std::cin >> IGNITION_WIRES;
                break;
            case 20:
                printf("Is the engine components GOOD OR BAD?");
                std::cin >> ENGINE_COMPONENTS;
                break;
            case 21:
                printf("Is the battery GOOD OR BAD?");
                std::cin >> BATTERY;
                break;
            case 22:
                printf("Is the alternator GOOD OR BAD?");
                std::cin >> ALTERNATOR;
                break;
            case 23:
                printf("Is the alternator belt GOOD OR BAD?");
                std::cin >> ALTERNATOR_BELT;
                break;
            case 24:
                printf("Is the battery wires GOOD OR BAD?");
                std::cin >> BATTERY_WIRES;
                break;
            case 25:
                printf("Is the electrical system GOOD OR BAD?");
                std::cin >> ELECTRICAL_SYSTEM;
                break;
            case 26:
                printf("Is the coolant GOOD OR BAD?");
                std::cin >> COOLANT;
                break;
            case 27:
                printf("Is the drive belt GOOD OR BAD?");
                std::cin >> DRIVE_BELT;
                break;
            case 28:
                printf("Is the radiator GOOD OR BAD?");
                std::cin >> RADIATOR;
                break;
            case 29:
                printf("Is the radiator fan GOOD OR BAD?");
                std::cin >> RADIATOR_FAN;
                break;
            case 30:
                printf("Is the water pump GOOD OR BAD?");
                std::cin >> WATER_PUMP;
                break;
            case 31:
                printf("Is the tire pressure GOOD OR BAD?");
                std::cin >> TIRE_PRESSURE;
                break;
            case 32:
                printf("Is the air filter GOOD OR BAD?");
                std::cin >> AIR_FILTER;
                break;
            case 33:
                printf("Is the fuel tank GOOD OR BAD?");
                std::cin >> FUEL_TANK;
                break;
            case 34:
                printf("Is the fuel management system GOOD OR BAD?");
                std::cin >> FUEL_MANAGEMENT_SYSTEM;
                break;
            case 35:
                printf("Is the brake parts GOOD OR BAD?");
                std::cin >> BRAKE_PARTS;
                break;
            case 36:
                printf("Is the brake parts GOOD OR BAD?");
                std::cin >> BRAKE_PARTS;
                break;
            case 37:
                printf("Is the brake lines GOOD OR BAD?");
                std::cin >> BRAKE_LINES;
                break;
            case 38:
                printf("Is the brake parts GOOD OR BAD?");
                std::cin >> BRAKE_PARTS;
                break;

        }
    }
    /* end of input statements for the position knowledge base */
}

//==========================================================================
/* Search clause variable list for a varialbe (clVarList) equal to the
one in front of the conclusion queue (cndVar). Return the statement
number (sn). If there is no match, i.e., sn=0, the first statement
for the space is flag. */
void fc::searchClauses()
{
    sn = flag;

    while ((flag == 1) && (sn <= 38))
    {
        cn=1;
        k = (sn-1)*38 + cn;
        //cout << sn << "  " << cndVar[fp] << endl;

        while ((strcmp(clVarList[k], cndVar[fp]) != 0) && (cn < 37))
        {
            cn = cn+1;
            k = (sn-1)*38 + cn;
        }
        if (strcmp(clVarList[k], cndVar[fp]) == 0)flag = 0;
        if (flag == 1) sn = sn+1;
    }

    if (flag == 1) sn=0;
}

//==========================================================================
/* Routine to instantiate a variable (v) and then place it on the
back of the queu (cndVar[bp]), if it is not already there. */
void fc::instantiate()
{
    i=1;
    /* find variable in the variable list (varList) */
    while ((strcmp(v, varList[i]) != 0) && (i <= 38)) i=i+1;

    /* instantiate it */
    instList[i] = 1;
    i = 1;

    /* determine if (v) is or already has been on the queue (cndVar) */
    while (((strcmp(v, cndVar[i]) != 0)) && (i <= 38)) i=i+1;

    /* variable has not been on the queue. Store it in the back of the queue */
    if (strcmp(v, cndVar[i]) != 0)
    {
        strcpy(cndVar[bp], v);
        bp=bp+1;
    }
}

