//bc.cpp
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>

#include "bc.h"

using namespace std;

char * bc::start() {
    /***** initialization section ******/
    sp = 45;
    for (i = 1; i < 45; i++) {
        strcpy(concList[i], "");
        strcpy(varList[i], "");
        instList[i] = 0;
        stateStk[i] = 0;
        clausStk[i] = 0;
    }
    for (i = 1; i < 1717; i++) strcpy(clVarList[i], "");

    /*populate conclusion list*/
    for (int i = 1; i < 40; i++) {
        strcpy(concList[i], "Part");
    }

    printf("*** CONCLUSION LIST ***\n");
    for (i = 1; i < 40; i++) printf("CONCLUSION %d %s\n", i, concList[i]);
    printf("HIT RETURN TO CONTINUE");
    gets(buff);

    /*populate variable list*/
    strcpy(varList[1], "PROBLEM");
    strcpy(varList[2], "OIL_PRESSURE");
    strcpy(varList[3], "OIL_FILTER");
    strcpy(varList[4], "OIL_GRADE");
    strcpy(varList[5], "LEAK");
    strcpy(varList[6], "OIL_LEAK");
    strcpy(varList[7], "COOLANT_LEAK");
    strcpy(varList[8], "TRANS_LEAK");
    strcpy(varList[9], "OIL_DRAIN_PLUG");
    strcpy(varList[10], "ENGINE_LEAK");
    strcpy(varList[11], "RADIATOR_LEAK");
    strcpy(varList[12], "RADIATOR_HOSE");
    strcpy(varList[13], "TRANS_DRAIN_PLUG");
    strcpy(varList[14], "ENGINE_ROTATES");
    strcpy(varList[15], "BATT_TERMINALS");
    strcpy(varList[16], "FUEL");
    strcpy(varList[17], "BATT_VOLTAGE");
    strcpy(varList[18], "START_MOTOR");
    strcpy(varList[19], "ROUGH");
    strcpy(varList[20], "VACUUM_HOSE");
    strcpy(varList[21], "SPARK_PLUGS");
    strcpy(varList[22], "BAD_FUEL");
    strcpy(varList[23], "FUEL_INJECTORS");
    strcpy(varList[24], "IGNITION_SWITCH");
    strcpy(varList[25], "KNOCKING");
    strcpy(varList[26], "BATT_CHARGE");
    strcpy(varList[27], "BATT_TEST");
    strcpy(varList[28], "ALTERNATOR");
    strcpy(varList[29], "ALT_DRIVE_BELT");
    strcpy(varList[30], "BATT_WIRES");
    strcpy(varList[31], "OVERHEAT");
    strcpy(varList[32], "COOLANT");
    strcpy(varList[33], "DRIVE_BELT");
    strcpy(varList[34], "RADIATOR");
    strcpy(varList[35], "RADIATOR_FAN");
    strcpy(varList[36], "FUEL_USE");
    strcpy(varList[37], "TIRE_PRESSURE");
    strcpy(varList[38], "AIR_FILTER");
    strcpy(varList[39], "FUEL_SMELL");
    strcpy(varList[40], "CHECK_BRAKE");
    strcpy(varList[41], "WOBBLE");
    strcpy(varList[42], "CHEMICAL_SMELL");
    strcpy(varList[43], "SPONGEY");
    strcpy(varList[44], "SQUEAK");

    printf("*** VARIABLE LIST *\n");
    for (i = 1; i < 45; i++) printf("VARIABLE %d %s\n", i, varList[i]);
    printf("HIT RETURN KEY TO CONTINUE");
    gets(buff);

    /*populate clause variable list*/
    strcpy(clVarList[1], "PROBLEM");
    strcpy(clVarList[45], "PROBLEM");
    strcpy(clVarList[46], "OIL_PRESSURE");
    strcpy(clVarList[47], "OIL_GRADE");
    strcpy(clVarList[48], "OIL_FILTER");
    strcpy(clVarList[89], "PROBLEM");
    strcpy(clVarList[90], "OIL_PRESSURE");
    strcpy(clVarList[91], "OIL_GRADE");
    strcpy(clVarList[92], "OIL_FILTER");
    strcpy(clVarList[133], "PROBLEM");
    strcpy(clVarList[134], "OIL_PRESSURE");
    strcpy(clVarList[135], "OIL_GRADE");
    strcpy(clVarList[177], "PROBLEM");
    strcpy(clVarList[178], "LEAK");
    strcpy(clVarList[179], "OIL_LEAK");
    strcpy(clVarList[180], "OIL_DRAIN_PLUG");
    strcpy(clVarList[221], "PROBLEM");
    strcpy(clVarList[222], "LEAK");
    strcpy(clVarList[223], "OIL_LEAK");
    strcpy(clVarList[224], "ENGINE_LEAK");
    strcpy(clVarList[265], "PROBLEM");
    strcpy(clVarList[266], "LEAK");
    strcpy(clVarList[267], "COOLANT_LEAK");
    strcpy(clVarList[268], "RADIATOR_LEAK");
    strcpy(clVarList[309], "PROBLEM");
    strcpy(clVarList[310], "LEAK");
    strcpy(clVarList[311], "COOLANT_LEAK");
    strcpy(clVarList[312], "RADIATOR_HOSE");
    strcpy(clVarList[353], "PROBLEM");
    strcpy(clVarList[354], "LEAK");
    strcpy(clVarList[355], "TRANS_LEAK");
    strcpy(clVarList[356], "TRANS_DRAIN_PLUG");
    strcpy(clVarList[397], "PROBLEM");
    strcpy(clVarList[398], "ENGINE_ROTATES");
    strcpy(clVarList[399], "BATT_TERMINALS");
    strcpy(clVarList[400], "BATT_VOLTAGE");
    strcpy(clVarList[441], "PROBLEM");
    strcpy(clVarList[442], "ENGINE_ROTATES");
    strcpy(clVarList[443], "BATT_TERMINALS");
    strcpy(clVarList[444], "BATT_VOLTAGE");
    strcpy(clVarList[445], "START_MOTOR");
    strcpy(clVarList[485], "PROBLEM");
    strcpy(clVarList[486], "ENGINE_ROTATES");
    strcpy(clVarList[487], "BATT_TERMINALS");
    strcpy(clVarList[488], "BATT_VOLTAGE");
    strcpy(clVarList[489], "START_MOTOR");
    strcpy(clVarList[529], "PROBLEM");
    strcpy(clVarList[530], "ENGINE_ROTATES");
    strcpy(clVarList[531], "BATT_TERMINALS");
    strcpy(clVarList[573], "PROBLEM");
    strcpy(clVarList[574], "ENGINE_ROTATES");
    strcpy(clVarList[575], "FUEL");
    strcpy(clVarList[617], "PROBLEM");
    strcpy(clVarList[618], "ENGINE_ROTATES");
    strcpy(clVarList[619], "FUEL");
    strcpy(clVarList[661], "PROBLEM");
    strcpy(clVarList[662], "ROUGH");
    strcpy(clVarList[663], "VACUUM_HOSE");
    strcpy(clVarList[705], "PROBLEM");
    strcpy(clVarList[706], "ROUGH");
    strcpy(clVarList[707], "SPARK_PLUGS");
    strcpy(clVarList[749], "PROBLEM");
    strcpy(clVarList[750], "ROUGH");
    strcpy(clVarList[751], "BAD_FUEL");
    strcpy(clVarList[793], "PROBLEM");
    strcpy(clVarList[794], "ROUGH");
    strcpy(clVarList[795], "FUEL_INJECTORS");
    strcpy(clVarList[837], "PROBLEM");
    strcpy(clVarList[838], "ROUGH");
    strcpy(clVarList[839], "IGNITION_WIRES");
    strcpy(clVarList[881], "PROBLEM");
    strcpy(clVarList[882], "ROUGH");
    strcpy(clVarList[883], "KNOCKING");
    strcpy(clVarList[925], "PROBLEM");
    strcpy(clVarList[926], "BATT_CHARGE");
    strcpy(clVarList[927], "BATT_TEST");
    strcpy(clVarList[969], "PROBLEM");
    strcpy(clVarList[970], "BATT_CHARGE");
    strcpy(clVarList[971], "BATT_TEST");
    strcpy(clVarList[972], "ALTERNATOR");
    strcpy(clVarList[1013], "PROBLEM");
    strcpy(clVarList[1014], "BATT_CHARGE");
    strcpy(clVarList[1015], "BATT_TEST");
    strcpy(clVarList[1016], "ALTERNATOR");
    strcpy(clVarList[1017], "ALT_DRIVE_BELT");
    strcpy(clVarList[1057], "PROBLEM");
    strcpy(clVarList[1058], "BATT_CHARGE");
    strcpy(clVarList[1059], "BATT_TEST");
    strcpy(clVarList[1060], "ALTERNATOR");
    strcpy(clVarList[1061], "ALT_DRIVE_BELT");
    strcpy(clVarList[1062], "BATT_WIRES");
    strcpy(clVarList[1101], "PROBLEM");
    strcpy(clVarList[1102], "BATT_CHARGE");
    strcpy(clVarList[1103], "BATT_TEST");
    strcpy(clVarList[1104], "ALTERNATOR");
    strcpy(clVarList[1105], "ALT_DRIVE_BELT");
    strcpy(clVarList[1106], "BATT_WIRES");
    strcpy(clVarList[1145], "PROBLEM");
    strcpy(clVarList[1146], "OVERHEAT");
    strcpy(clVarList[1147], "COOLANT");
    strcpy(clVarList[1189], "PROBLEM");
    strcpy(clVarList[1190], "OVERHEAT");
    strcpy(clVarList[1191], "COOLANT");
    strcpy(clVarList[1192], "DRIVE_BELT");
    strcpy(clVarList[1233], "PROBLEM");
    strcpy(clVarList[1234], "OVERHEAT");
    strcpy(clVarList[1235], "COOLANT");
    strcpy(clVarList[1236], "DRIVE_BELT");
    strcpy(clVarList[1237], "RADIATOR");
    strcpy(clVarList[1277], "PROBLEM");
    strcpy(clVarList[1278], "OVERHEAT");
    strcpy(clVarList[1279], "COOLANT");
    strcpy(clVarList[1280], "DRIVE_BELT");
    strcpy(clVarList[1281], "RADIATOR");
    strcpy(clVarList[1282], "RADIATOR_FAN");
    strcpy(clVarList[1321], "PROBLEM");
    strcpy(clVarList[1322], "OVERHEAT");
    strcpy(clVarList[1323], "COOLANT");
    strcpy(clVarList[1324], "DRIVE_BELT");
    strcpy(clVarList[1325], "RADIATOR");
    strcpy(clVarList[1326], "RADIATOR_FAN");
    strcpy(clVarList[1365], "PROBLEM");
    strcpy(clVarList[1366], "FUEL_USE");
    strcpy(clVarList[1364], "TIRE_PRESSURE");
    strcpy(clVarList[1409], "PROBLEM");
    strcpy(clVarList[1410], "FUEL_USE");
    strcpy(clVarList[1411], "TIRE_PRESSURE");
    strcpy(clVarList[1412], "AIR_FILTER");
    strcpy(clVarList[1453], "PROBLEM");
    strcpy(clVarList[1454], "FUEL_USE");
    strcpy(clVarList[1455], "TIRE_PRESSURE");
    strcpy(clVarList[1456], "AIR_FILTER");
    strcpy(clVarList[1457], "FUEL_SMELL");
    strcpy(clVarList[1497], "PROBLEM");
    strcpy(clVarList[1498], "FUEL_USE");
    strcpy(clVarList[1499], "TIRE_PRESSURE");
    strcpy(clVarList[1500], "AIR_FILTER");
    strcpy(clVarList[1501], "FUEL_SMELL");
    strcpy(clVarList[1541], "PROBLEM");
    strcpy(clVarList[1542], "CHECK_BRAKE");
    strcpy(clVarList[1543], "WOBBLE");
    strcpy(clVarList[1585], "PROBLEM");
    strcpy(clVarList[1586], "CHECK_BRAKE");
    strcpy(clVarList[1587], "CHEMICAL_SMELL");
    strcpy(clVarList[1629], "PROBLEM");
    strcpy(clVarList[1630], "CHECK_BRAKE");
    strcpy(clVarList[1631], "SPONGEY");
    strcpy(clVarList[1673], "PROBLEM");
    strcpy(clVarList[1674], "CHECK_BRAKE");
    strcpy(clVarList[1675], "SQUEAK");

    printf("*** CLAUSE VARIABLE LIST ***\n");
    for (i = 1; i < 40; i++) {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 45; j++) {
            k = 44 * (i - 1) + j;
            printf("VARIABLE %d  %s\n", j, clVarList[k]);
        }
    }

    /****** inference section *****/
    printf("** ENTER CONCLUSION : ");
    gets(varble);
    /* get conclusion statement number (stateNum) from the conclusion list
       (concList) */
    /* first statement starts search */
    bcLoop();
    return end;
}

void bc::determine_member_concl_list() {
/* routine to determine if a variable (varble) is a member of the
   conclusion list (concList).  if yes return stateNum != 0.
   if not a member stateNum=0;
*/
    /* initially set to not a member */
    stateNum = 0;
    /* member of conclusion list to be searched is flag */
    i = flag;
    while((strcmp(varble, concList[i]) != 0) && (i<40))
        /* test for membership */
    {
        i=i+1;
    }

    if (strcmp(varble, concList[i]) == 0) stateNum = i;  /* a member */
}

void bc::push_on_stack()
/* routine to push statement number (stateNum) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (stateStk) and the
clause stack (clausStk)..to push decrement stack pointer (sp) */
{
    sp=sp-1;
    stateStk[sp] = stateNum;
    clausStk[sp] = 1;
}

void bc::instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instList) is a 0 if not, a 1 if it is.  the
variable list (varList) contains the variable (varble). */
{
    i=1;
    /* find variable in the list */
    while((strcmp(varble, varList[i]) != 0) && (i<45)) i=i+1;
    if((strcmp(varble, varList[i]) == 0) && (instList[i] != 1))
        /*found variable and not already instantiated */
    {
        instList[i]=1; /*mark instantiated */
        /* the designer of the
       knowledge base places the input statements to
       instantiate the variables below in the case statement */
        switch (i)
        {
            /***** input statement *****/
            /* input statements for sample position knowledge base */
            case 1: printf("Is there a problem with the car? INPUT YES OR NO");
                gets(PROBLEM);
                break;
            case 2: printf("Is the oil pressure low? INPUT YES OR NO");
                gets(OIL_PRESSURE);
                break;
            case 3: printf("Is the oil filter new? INPUT YES OR NO");
                gets(OIL_FILTER);
                break;
            case 4: printf("Is the oil grade correct? INPUT YES OR NO");
                gets(OIL_GRADE);
                break;
            case 5: printf("Do you see a leak? INPUT YES OR NO");
                gets(LEAK);
                break;
            case 6: printf("Is it an oil leak? INPUT YES OR NO");
                gets(OIL_LEAK);
                break;
            case 7: printf("Is it a coolant leak? INPUT YES OR NO");
                gets(COOLANT_LEAK);
                break;
            case 8: printf("Is it a transmission fluid leak? INPUT YES OR NO");
                gets(TRANS_LEAK);
                break;
            case 9: printf("Is the leak coming from the oil drain plug? INPUT YES OR NO");
                gets(OIL_DRAIN_PLUG);
                break;
            case 10: printf("Is the leak coming from a seam in the engine? INPUT YES OR NO");
                gets(ENGINE_LEAK);
                break;
            case 11: printf("Is the leak coming from the radiator? INPUT YES OR NO");
                gets(RADIATOR_LEAK);
                break;
            case 12: printf("Is the leak coming from a radiator hose? INPUT YES OR NO");
                gets(RADIATOR_HOSE);
                break;
            case 13: printf("Is the leak coming from the transmission drain plug? INPUT YES OR NO");
                gets(TRANS_DRAIN_PLUG);
                break;
            case 14: printf("Does the engine rotate when starting? INPUT YES OR NO");
                gets(ENGINE_ROTATES);
                break;
            case 15: printf("Are the battery terminals connected? INPUT YES OR NO");
                gets(BATT_TERMINALS);
                break;
            case 16: printf("Is there fuel in the tank? INPUT YES OR NO");
                gets(FUEL);
                break;
            case 17: printf("What is the battery voltage? INPUT A REAL NUMBER");
                std::cin >> BATT_VOLTAGE;
                gets(buff);
                break;
            case 18: printf("Is the starter motor working? INPUT YES OR NO");
                gets(START_MOTOR);
                break;
            case 19: printf("Is the car running roughly? INPUT YES OR NO");
                gets(ROUGH);
                break;
            case 20: printf("Are the vacuum hoses worn? INPUT YES OR NO");
                gets(VACUUM_HOSE);
                break;
            case 21: printf("Do the spark plugs looked burned or corroded? INPUT YES OR NO");
                gets(SPARK_PLUGS);
                break;
            case 22: printf("Is there water in the fuel? INPUT YES OR NO");
                gets(BAD_FUEL);
                break;
            case 23: printf(" Do the injectors look clogged or corroded? INPUT YES OR NO");
                gets(FUEL_INJECTORS);
                break;
            case 24: printf("Do the ignition wired look worn or cracked? INPUT YES OR NO");
                gets(IGNITION_WIRES);
                break;
            case 25: printf("Is there a knocking noise coming from inside the engine? INPUT YES OR NO");
                gets(KNOCKING);
                break;
            case 26: printf("Does the battery hold a charge? INPUT YES OR NO");
                gets(BATT_CHARGE);
                break;
            case 27: printf("Does the battery test ok? INPUT YES OR NO");
                gets(BATT_TEST);
                break;
            case 28: printf("Does the alternator test ok? INPUT YES OR NO");
                gets(ALTERNATOR);
                break;
            case 29: printf("Does the alternator drive belt look worn? INPUT YES OR NO");
                gets(ALT_DRIVE_BELT);
                break;
            case 30: printf("Are the battery wires worn or cracked? INPUT YES OR NO");
                gets(BATT_WIRES);
                break;
            case 31: printf("Does the car overheat? INPUT YES OR NO");
                gets(OVERHEAT);
                break;
            case 32: printf("Is there coolant? INPUT YES OR NO");
                gets(COOLANT);
                break;
            case 33: printf("Is the drive belt worn or stretched? INPUT YES OR NO");
                gets(DRIVE_BELT);
                break;
            case 34: printf("Does the radiator look dirty or corroded? INPUT YES OR NO");
                gets(RADIATOR);
                break;
            case 35: printf("Does the radiator fan work? INPUT YES OR NO");
                gets(RADIATOR_FAN);
                break;
            case 36: printf("Is there excessive fuel consumption? INPUT YES OR NO");
                gets(FUEL_USE);
                break;
            case 37: printf("Is the tire pressure correct? INPUT YES OR NO");
                gets(TIRE_PRESSURE);
                break;
            case 38: printf("Does the air filter look clean? INPUT YES OR NO");
                gets(AIR_FILTER);
                break;
            case 39: printf("Can you smell fuel under the car?INPUT YES OR NO");
                gets(FUEL_SMELL);
                break;
            case 40: printf("Is the check brake light on? INPUT YES OR NO");
                gets(CHECK_BRAKE);
                break;
            case 41: printf("Is there a wobble or vibration when braking? INPUT YES OR NO");
                gets(WOBBLE);
                break;
            case 42: printf("Is there a chemical burning smell when braking? INPUT YES OR NO");
                gets(CHEMICAL_SMELL);
                break;
            case 43: printf("Is braking spongey or soft? INPUT YES OR NO");
                gets(SPONGEY);
                break;
            case 44: printf("Is there a squeaking noise when braking?INPUT YES OR NO");
                gets(SQUEAK);
                break;




                /***** comment 1715 ****/
        }
        /* end of inputs statements for sample position knowledge
           base */
    }
}

void bc::bcLoop(){
    flag=1;
    determine_member_concl_list();

    if (stateNum != 0) { /* if stateNum = 0 then no conclusion of that name */
        /* push statement number (stateNum) and clause number=1 on goal
        stack which is composed of the statement stack (stateStk)
        and clause stack (clausStk) */
        do
        {
            push_on_stack();
            do
            {
                /* calculate clause location in clause-variable
                   list */
                chkClauses();
            } while(strcmp(varble, "") != 0); /*do-while*/
            /*no more clauses check if part of statement */
            stateNum = stateStk[sp];
            s = 0;
            /**** if then statements ****/
            /* sample if parts of if then statements from
               the position knowledge base */
            switch (stateNum) {
                /* if part of statement 1 */
                /****** comment 1500 ****/
                case 1: if(strcmp(PROBLEM, "NO") == 0) s = 1;
                    break;
                    /* if part of statement 2 */
                    /***** comment 1510 ******/
                case 2: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(OIL_PRESSURE, "YES") == 0)&&
                           (strcmp(OIL_GRADE, "YES") == 0)&&
                           (strcmp(OIL_FILTER, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 3 */
                case 3:
                    if ((strcmp(PROBLEM, "YES") == 0) &&
                        (strcmp(OIL_PRESSURE, "YES") == 0) &&
                        (strcmp(OIL_GRADE, "YES") == 0) &&
                        (strcmp(OIL_FILTER, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 4: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(OIL_PRESSURE, "YES") == 0) &&
                           (strcmp(OIL_GRADE, "NO") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 5: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(LEAK, "YES") == 0) &&
                           (strcmp(OIL_LEAK, "YES") == 0) &&
                           (strcmp(OIL_DRAIN_PLUG, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 6: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(LEAK, "YES") == 0) &&
                           (strcmp(OIL_LEAK, "YES") == 0) &&
                           (strcmp(ENGINE_LEAK, "YES") == 0)) s = 1;
                    break;
                case 7: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(LEAK, "YES") == 0) &&
                           (strcmp(COOLANT_LEAK, "YES") == 0) &&
                           (strcmp(RADIATOR_LEAK, "YES") == 0)) s = 1;
                    break;

                case 8:
                    if ((strcmp(PROBLEM, "YES") == 0) &&
                        (strcmp(LEAK, "YES") == 0) &&
                        (strcmp(COOLANT_LEAK, "YES") == 0) &&
                        (strcmp(RADIATOR_HOSE, "YES") == 0)) s = 1;
                    break;

                case 9: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(LEAK, "YES") == 0) &&
                           (strcmp(TRANS_LEAK, "YES") == 0) &&
                           (strcmp(TRANS_DRAIN_PLUG, "YES") == 0)) s = 1;
                    break;

                case 10: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                            (strcmp(BATT_TERMINALS, "YES") == 0) &&
                            (BATT_VOLTAGE<12)) s = 1;
                    break;

                case 11: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                            (strcmp(BATT_TERMINALS, "YES") == 0) &&
                            (BATT_VOLTAGE >= 12.0) &&
                            (strcmp(START_MOTOR, "YES") == 0) )s = 1;
                    break;
                case 12: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                            (strcmp(BATT_TERMINALS, "YES") == 0) &&
                            (BATT_VOLTAGE>=12)&&
                            (strcmp(START_MOTOR, "NO") == 0) )s = 1;

                case 13:
                    if ((strcmp(PROBLEM, "YES") == 0) &&
                        (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                        (strcmp(BATT_TERMINALS, "NO") == 0)) s = 1;
                    break;

                case 14: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "YES") == 0) &&
                            (strcmp(FUEL, "NO") == 0)) s = 1;
                    break;

                case 15: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "YES") == 0) &&
                            (strcmp(FUEL, "YES") == 0)) s = 1;
                    break;

                case 16: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(VACUUM_HOSE, "YES") == 0)) s = 1;
                    break;
                case 17: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(SPARK_PLUGS, "YES") == 0)) s = 1;
                    break;

                case 18:
                    if((strcmp(PROBLEM, "YES") == 0) &&
                       (strcmp(ROUGH, "YES") == 0) &&
                       (strcmp(BAD_FUEL, "YES") == 0)) s = 1;
                    break;

                case 19: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(FUEL_INJECTORS, "YES") == 0)) s = 1;
                    break;

                case 20: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(IGNITION_WIRES, "YES") == 0)) s = 1;
                    break;

                case 21: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(KNOCKING, "YES") == 0)) s = 1;
                    break;
                case 22: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "NO") == 0)) s = 1;
                    break;

                case 23:
                    if((strcmp(PROBLEM, "YES") == 0) &&
                       (strcmp(BATT_CHARGE, "NO") == 0) &&
                       (strcmp(BATT_TEST, "YES") == 0) &&
                       (strcmp(ALTERNATOR, "NO") == 0)) s = 1;
                    break;

                case 24: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "YES") == 0) &&
                            (strcmp(ALTERNATOR, "YES") == 0)&&
                            (strcmp(ALT_DRIVE_BELT, "YES") == 0)) s = 1;
                    break;

                case 25: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "YES") == 0) &&
                            (strcmp(ALTERNATOR, "YES") == 0)&&
                            (strcmp(ALT_DRIVE_BELT, "YES") == 0)&&
                            (strcmp(BATT_WIRES, "YES") == 0)) s = 1;
                    break;

                case 26: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "YES") == 0) &&
                            (strcmp(ALTERNATOR, "YES") == 0)&&
                            (strcmp(ALT_DRIVE_BELT, "YES") == 0)&&
                            (strcmp(BATT_WIRES, "NO") == 0)) s = 1;
                    break;
                case 27: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(COOLANT, "NO") == 0)) s = 1;
                    break;

                case 28: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(DRIVE_BELT, "YES") == 0)) s = 1;
                    break;

                case 29: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(COOLANT, "YES") == 0)&&
                            (strcmp(DRIVE_BELT, "NO") == 0)&&
                            (strcmp(RADIATOR, "YES") == 0)) s = 1;
                    break;
                case 30: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(COOLANT, "YES") == 0)&&
                            (strcmp(DRIVE_BELT, "NO") == 0)&&
                            (strcmp(RADIATOR, "NO") == 0)&&
                            (strcmp(RADIATOR_FAN, "NO") == 0)) s = 1;
                    break;

                case 31:
                    if((strcmp(PROBLEM, "YES") == 0) &&
                       (strcmp(OVERHEAT, "YES") == 0) &&
                       (strcmp(COOLANT, "YES") == 0)&&
                       (strcmp(DRIVE_BELT, "NO") == 0)&&
                       (strcmp(RADIATOR, "NO") == 0)&&
                       (strcmp(RADIATOR_FAN, "YES") == 0)) s = 1;
                    break;

                case 32: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "NO") == 0)) s = 1;
                    break;

                case 33: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "YES") == 0) &&
                            (strcmp(AIR_FILTER, "NO") == 0)) s = 1;
                    break;

                case 34: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "YES") == 0) &&
                            (strcmp(AIR_FILTER, "YES") == 0)&&
                            (strcmp(FUEL_SMELL, "YES") == 0)) s = 1;
                    break;
                case 35: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "YES") == 0) &&
                            (strcmp(AIR_FILTER, "YES") == 0)&&
                            (strcmp(FUEL_SMELL, "NO") == 0)) s = 1;
                    break;

                case 36: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(CHECK_BRAKE, "YES") == 0) &&
                            (strcmp(WOBBLE, "YES") == 0)) s = 1;
                    break;
                case 37: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(CHECK_BRAKE, "YES") == 0) &&
                            (strcmp(CHEMICAL_SMELL, "YES") == 0)) s = 1;
                    break;

                case 38:if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(CHECK_BRAKE, "YES") == 0) &&
                           (strcmp(SPONGEY, "YES") == 0)) s = 1;
                    break;
                case 39: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(CHECK_BRAKE, "YES") == 0) &&
                            (strcmp(SQUEAK, "YES") == 0)) s = 1;
                    break;

            }
            /* see if the then part should be invoked */
            if( s != 1) {
                /* failed..search rest of statements for
                   same conclusion */
                /* get conclusion */
                i = stateStk[sp];
                strcpy(varble, concList[i]);
                /* search for conclusion starting at the
                   next statement number */
                flag = stateStk[sp] + 1;
                determine_member_concl_list();
                sp = sp+1;
            }
            /* pop old conclusion and put on new one */
        } while((s != 1) && (stateNum !=0));  /* outer do-while loop */
        if(stateNum != 0){
            /* if part true invoke then part */
            /* then part of if-then statements from the
               position knowledge base */
            switch (stateNum) {
                /* then part of statement 1 */
                /******* comment 1500 *******/
                case 1: strcpy(PROBLEM, "NO");
                    printf("NO ISSUE\n");
                    strcpy(end, "NO ISSUE");
                    break;
                    /* then part of statement 2 */
                    /****** comment 1510 ******/
                case 2: strcpy(PART, "YES");
                    printf("PART = OIL PUMP\n");
                    strcpy(end, "OIL_PUMP");
                    break;
                    /* then part of statement 3 */
                case 3: strcpy(PART, "YES");
                    printf("PART = OIL FILTER\n");
                    strcpy(end, "OIL_FILTER");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 4: strcpy(PART, "YES");
                    printf("OIL\n");
                    strcpy(end, "OIL");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 5: strcpy(PART, "YES");
                    printf("OIL DRAIN PLUG\n");
                    strcpy(end, "OIL_DRAIN_PLUG");
                    break;

                case 6: strcpy(PART, "YES");
                    printf("ENGINE GASKET\n");
                    strcpy(end, "ENGINE_GASKET");
                    break;
                case 7: strcpy(PART, "YES");
                    printf("RADIATOR\n");
                    strcpy(end,"RADIATOR");
                    break;

                case 8: strcpy(PART, "YES");
                    printf("RADIATOR HOSE\n");
                    strcpy(end,"RADIATOR_HOSE");
                    break;

                case 9: strcpy(PART, "YES");
                    printf("TRANSMISSION DRAIN PLUG\n");
                    strcpy(end,"TRANSMISSION_DRAIN_PLUG");
                    break;

                case 10: strcpy(PART, "YES");
                    printf("BATTERY\n");
                    strcpy(end,"BATTERY");
                    break;

                case 11: strcpy(PART, "YES");
                    printf("IGNITION SWITCH\n");
                    strcpy(end,"IGNITION_SWITCH");
                    break;
                case 12: strcpy(PART, "YES");
                    printf("STARTER MOTOR\n");
                    strcpy(end,"STARTER_MOTOR");
                    break;

                case 13: strcpy(PART, "YES");
                    printf("BATTERY TERMINALS\n");
                    strcpy(end,"BATTERY_TERMINALS");
                    break;

                case 14: strcpy(PART, "YES");
                    printf("FUEL LEVEL\n");
                    strcpy(end,"FUEL_LEVEL");
                    break;

                case 15: strcpy(PART, "YES");
                    printf("FUEL SYSTEM\n");
                    strcpy(end,"FUEL_SYSTEM");
                    break;

                case 16: strcpy(PART, "YES");
                    printf("VACUUM HOSE\n");
                    strcpy(end,"VACUUM_HOSE");
                    break;
                case 17: strcpy(PART, "YES");
                    printf("SPARK PLUGS\n");
                    strcpy(end,"SPARK_PLUGS");
                    break;

                case 18: strcpy(PART, "YES");
                    printf("FUEL CONDITION\n");
                    strcpy(end,"FUEL_CONDITION");
                    break;

                case 19: strcpy(PART, "YES");
                    printf("FUEL INJECTORS\n");
                    strcpy(end,"FUEL_INJECTORS");
                    break;

                case 20: strcpy(PART, "YES");
                    printf("IGNITION WIRES\n");
                    strcpy(end,"IGNITION_WIRES");
                    break;

                case 21: strcpy(PART, "YES");
                    printf("ENGINE COMPONENTS\n");
                    strcpy(end,"ENGINE_COMPONENTS");
                    break;
                case 22: strcpy(PART, "YES");
                    printf("BATTERY\n");
                    strcpy(end,"BATTERY");
                    break;

                case 23: strcpy(PART, "YES");
                    printf("ALTERNATOR\n");
                    strcpy(end,"ALTERNATOR");
                    break;

                case 24: strcpy(PART, "YES");
                    printf("ALTERNATOR DRIVE BELT\n");
                    strcpy(end,"ALTERNATOR_DRIVE_BELT");
                    break;

                case 25: strcpy(PART, "YES");
                    printf("BATTERY WIRES\n");
                    strcpy(end,"BATTERY_WIRES");
                    break;

                case 26: strcpy(PART, "YES");
                    printf("ELECTRICAL SYSTEM\n");
                    strcpy(end,"ELECTRICAL_SYSTEM");
                    break;
                case 27: strcpy(PART, "YES");
                    printf("COOLANT\n");
                    strcpy(end,"COOLANT");
                    break;

                case 28: strcpy(PART, "YES");
                    printf("DRIVE BELT\n");
                    strcpy(end,"DRIVE_BELT");
                    break;

                case 29: strcpy(PART, "YES");
                    printf("RADIATOR\n");
                    strcpy(end,"RADIATOR");
                    break;

                case 30: strcpy(PART, "YES");
                    printf("RADIATOR FAN\n");
                    strcpy(end,"RADIATOR_FAN");
                    break;

                case 31: strcpy(PART, "YES");
                    printf("WATTER PUMP\n");
                    strcpy(end,"WATTER_PUMP");
                    break;
                case 32: strcpy(PART, "YES");
                    printf("TIRE PRESSURE\n");
                    strcpy(end,"TIRE_PRESSURE");
                    break;
                case 33: strcpy(PART, "YES");
                    printf("AIR FILTER\n");
                    strcpy(end,"AIR_FILTER");
                    break;
                case 34: strcpy(PART, "YES");
                    printf("FUEL TANK\n");
                    strcpy(end,"FUEL_TANK");
                    break;
                case 35: strcpy(PART, "YES");
                    printf("FUEL MANAGEMENT SYSTEM\n");
                    strcpy(end,"FUEL_MANAGEMENT_SYSTEM");
                    break;
                case 36: strcpy(PART, "YES");
                    printf("BRAKE PARTS\n");
                    strcpy(end,"BRAKE_PARTS");
                    break;
                case 37: strcpy(PART, "YES");
                    printf("BRAKE PARTS\n");
                    strcpy(end,"BRAKE_PARTS");
                    break;
                case 38: strcpy(PART, "YES");
                    printf("BRAKE LINES\n");
                    strcpy(end,"BRAKE_LINES");
                    break;
                case 39: strcpy(PART, "YES");
                    printf("BRAKE PARTS\n");
                    strcpy(end,"BRAKE_PARTS");
                    break;
            }

            popStack();
        }
    }
}

void bc::popStack()
{
    sp=sp+1;
    if(sp >= 45) /* finished */
        printf("*** SUCCESS\n");
    else {
        /* stack is not empty */
        /* get next clause then continue */
        clausStk[sp] = clausStk[sp]+1;
        chkClauses();
    }
}

void bc::chkClauses()
{
    i = (stateStk[sp] - 1) * 44 + clausStk[sp];
    /* clause variable */
    strcpy(varble, clVarList[i]);
    if (strcmp(varble, "") != 0) {
        /*is this clause variable a conclusion? */
        flag = 1;
        determine_member_concl_list();
        if (stateNum != 0)
            /* it is a conclusion push it */
            bcLoop();
        /* check instantiation of this clause */
        instantiate();
        clausStk[sp] = clausStk[sp] + 1;
    }
}

