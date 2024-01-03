    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% rtP.Vg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant_Value
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.StateSpace_P1_Size
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.StateSpace_P1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% rtP.StateSpace_P2_Size
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 106;

                    ;% rtP.StateSpace_P2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 108;

                    ;% rtP.StateSpace_P3_Size
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 112;

                    ;% rtP.StateSpace_P3
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 114;

                    ;% rtP.StateSpace_P4_Size
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 117;

                    ;% rtP.StateSpace_P4
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 119;

                    ;% rtP.StateSpace_P5_Size
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 629;

                    ;% rtP.StateSpace_P5
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 631;

                    ;% rtP.StateSpace_P6_Size
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 635;

                    ;% rtP.StateSpace_P6
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 637;

                    ;% rtP.StateSpace_P7_Size
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 639;

                    ;% rtP.StateSpace_P7
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 641;

                    ;% rtP.StateSpace_P8_Size
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 643;

                    ;% rtP.StateSpace_P8
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 645;

                    ;% rtP.StateSpace_P9_Size
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 647;

                    ;% rtP.StateSpace_P9
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 649;

                    ;% rtP.StateSpace_P10_Size
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 650;

                    ;% rtP.StateSpace_P10
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 652;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 653;

                    ;% rtP.Step_Time
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 654;

                    ;% rtP.Step_Y0
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 655;

                    ;% rtP.Step_YFinal
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 656;

                    ;% rtP.Gain_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 657;

                    ;% rtP.Constant4_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 658;

                    ;% rtP.Constant2_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 659;

                    ;% rtP.uib2_Gain
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 660;

                    ;% rtP.HitCrossing_Offset
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 661;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 662;

                    ;% rtP.eee_Value
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 663;

                    ;% rtP.gate_Value
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 664;

                    ;% rtP.qqq_Value
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 665;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% rtB.fwysot0tgt
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.bw1ymovkkk
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.pq340nhst2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% rtB.kkianidgen
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% rtB.lnkhi50vct
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% rtB.lkoyo2evq0
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% rtB.hvqeao5zds
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% rtB.b0fcxxvygu
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% rtB.kj1zvpheax
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% rtB.pkqujry2qj
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% rtB.ariy0mmiqe
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% rtB.jjy1g5xce0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

                    ;% rtB.jpmk5wbcjk
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 15;

                    ;% rtB.hraw2xzx1x
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 16;

                    ;% rtB.bljlccxajx
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.lbaw0ywzgf
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.argr3txhnv
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.egvifce2ld
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.kgui5h3axe
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.nvd2ol0qok.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 22;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.ob3vhelakn
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cyzctsgtgq
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 23;

                    ;% rtDW.edbkmdbvou
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 26;

                    ;% rtDW.funlkrtj1r
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.ig1xezdoi0
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.pbqtcwhcnj
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2557054502;
    targMap.checksum1 = 512478207;
    targMap.checksum2 = 2494288392;
    targMap.checksum3 = 1325535860;

