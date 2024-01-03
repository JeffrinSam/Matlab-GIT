#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "BOOst_mppt_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 18
#endif
#ifndef SS_INT64
#define SS_INT64 19
#endif
#else
#include "builtin_typeid_types.h"
#include "BOOst_mppt.h"
#include "BOOst_mppt_capi.h"
#include "BOOst_mppt_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"BOOst_mppt/Constant" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
0 , TARGET_STRING ( "BOOst_mppt/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 2 , 0 , TARGET_STRING ( "BOOst_mppt/Step" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Data Type Conversion" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 5 , 0 , TARGET_STRING (
"BOOst_mppt/Voltage Measurement/do not delete this gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"BOOst_mppt/Diode/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 7 , 0 , TARGET_STRING ( "BOOst_mppt/Diode/Model/eee" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"BOOst_mppt/IGBT/Model/qqq" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 9 , 0 , TARGET_STRING ( "BOOst_mppt/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
1 , 0 , 1 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 12 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 13 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/1\\ib2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 15 , 0 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Unit Delay" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 16 , TARGET_STRING ( "BOOst_mppt/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
"BOOst_mppt/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 18 ,
TARGET_STRING ( "BOOst_mppt/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0
} , { 19 , TARGET_STRING ( "BOOst_mppt/Step" ) , TARGET_STRING ( "After" ) ,
0 , 0 , 0 } , { 20 , TARGET_STRING (
"BOOst_mppt/Voltage Measurement/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
"BOOst_mppt/Diode/Model/(gate)" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 22 , TARGET_STRING ( "BOOst_mppt/Diode/Model/eee" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING ( "BOOst_mppt/IGBT/Model/qqq"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Compare To Zero/Constant" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" )
, 0 , 2 , 0 } , { 26 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" )
, 0 , 3 , 0 } , { 27 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P3" )
, 0 , 4 , 0 } , { 28 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" )
, 0 , 5 , 0 } , { 29 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P5" )
, 0 , 6 , 0 } , { 30 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P6" )
, 0 , 7 , 0 } , { 31 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P7" )
, 0 , 8 , 0 } , { 32 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P8" )
, 0 , 7 , 0 } , { 33 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P9" )
, 0 , 0 , 0 } , { 34 , TARGET_STRING (
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P10"
) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/1\\ib2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"BOOst_mppt/PWM Generator (DC-DC)/Sawtooth Generator/Model/Unit Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 40 , TARGET_STRING ( "Vg"
) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . jjy1g5xce0 , & rtB . lnkhi50vct ,
& rtB . kkianidgen , & rtB . pkqujry2qj , & rtB . kj1zvpheax , & rtB .
pq340nhst2 , & rtB . hraw2xzx1x , & rtB . jpmk5wbcjk , & rtB . bljlccxajx , &
rtB . fwysot0tgt , & rtB . bw1ymovkkk [ 0 ] , & rtB . hvqeao5zds , & rtB .
lkoyo2evq0 , & rtB . b0fcxxvygu , & rtB . lbaw0ywzgf , & rtB . ariy0mmiqe , &
rtP . Gain_Gain , & rtP . Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal ,
& rtP . donotdeletethisgain_Gain , & rtP . gate_Value , & rtP . eee_Value , &
rtP . qqq_Value , & rtP . Constant_Value , & rtP . StateSpace_P1 [ 0 ] , &
rtP . StateSpace_P2 [ 0 ] , & rtP . StateSpace_P3 [ 0 ] , & rtP .
StateSpace_P4 [ 0 ] , & rtP . StateSpace_P5 [ 0 ] , & rtP . StateSpace_P6 [ 0
] , & rtP . StateSpace_P7 [ 0 ] , & rtP . StateSpace_P8 [ 0 ] , & rtP .
StateSpace_P9 , & rtP . StateSpace_P10 , & rtP . Constant2_Value , & rtP .
Constant4_Value , & rtP . uib2_Gain , & rtP . HitCrossing_Offset , & rtP .
UnitDelay_InitialCondition , & rtP . Vg , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 4 , 1 , 17 , 6 , 1 , 4 , 3 , 1 , 17 , 30 , 2 , 2 , 1 , 2 , 2 , 1 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 5.0E-6 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 3 , 0 }
, { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 2
] , ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 2 , ( uint8_T )
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 16 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 24 ,
rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2557054502U , 512478207U , 2494288392U , 1325535860U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * BOOst_mppt_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void BOOst_mppt_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void BOOst_mppt_host_InitializeDataMapInfo ( BOOst_mppt_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
