#include "BOOst_mppt.h"
#include "mwmathutil.h"
#include "rtwtypes.h"
#include "BOOst_mppt_private.h"
#include "rt_logging_mmi.h"
#include "BOOst_mppt_capi.h"
#include "zero_crossing_types.h"
#include "BOOst_mppt_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.7 (R2022a) 13-Nov-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; void MdlInitialize ( void ) { { SimStruct
* rts = ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . argr3txhnv = rtP .
UnitDelay_InitialCondition ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtB . jjy1g5xce0 = rtP . Vg ; rtB . jpmk5wbcjk = rtP . eee_Value ; rtB .
bljlccxajx = rtP . qqq_Value ; { SimStruct * rts = ssGetSFunction ( rtS , 0 )
; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { boolean_T fi3r5db31z ;
ZCEventType zcEvent ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnOutputs ( rts , 0 ) ; } rtB . pq340nhst2 = rtP . donotdeletethisgain_Gain
* rtB . fwysot0tgt ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . edbkmdbvou
= ( ssGetTaskTime ( rtS , 1 ) >= rtP . Step_Time ) ; if ( rtDW . edbkmdbvou
== 1 ) { rtB . kkianidgen = rtP . Step_YFinal ; } else { rtB . kkianidgen =
rtP . Step_Y0 ; } } rtB . lnkhi50vct = ( rtB . kkianidgen - rtB . pq340nhst2
) * rtP . Gain_Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . ig1xezdoi0 = ( rtB . lnkhi50vct !=
rtP . Constant_Value ) ; } fi3r5db31z = rtDW . ig1xezdoi0 ; rtB . lkoyo2evq0
= rtP . Constant4_Value ; rtB . hvqeao5zds = rtP . Constant2_Value ; } rtB .
b0fcxxvygu = muDoubleScalarRem ( ssGetT ( rtS ) + rtB . lkoyo2evq0 , rtB .
hvqeao5zds ) * rtP . uib2_Gain ; rtB . kj1zvpheax = ( ( 2.0 * rtB .
b0fcxxvygu - 1.0 ) + 1.0 ) * 0.5 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . pbqtcwhcnj = ( rtB . lnkhi50vct
>= rtB . kj1zvpheax ) ; } rtB . pkqujry2qj = ( fi3r5db31z && rtDW .
pbqtcwhcnj ) ; zcEvent = rt_ZCFcn ( ANY_ZERO_CROSSING , & rtPrevZCX .
nf4mt1cq5r , ( rtB . b0fcxxvygu - rtP . HitCrossing_Offset ) ) ; if ( rtDW .
funlkrtj1r == 0 ) { if ( zcEvent != NO_ZCEVENT ) { rtB . lbaw0ywzgf = ! rtB .
lbaw0ywzgf ; rtDW . funlkrtj1r = 1 ; } else if ( rtB . lbaw0ywzgf ) { rtB .
lbaw0ywzgf = ( ( ! ( rtB . b0fcxxvygu != rtP . HitCrossing_Offset ) ) && rtB
. lbaw0ywzgf ) ; } else { rtB . lbaw0ywzgf = ( ( rtB . b0fcxxvygu == rtP .
HitCrossing_Offset ) || rtB . lbaw0ywzgf ) ; } } else { rtB . lbaw0ywzgf = (
( ! ( rtB . b0fcxxvygu != rtP . HitCrossing_Offset ) ) && rtB . lbaw0ywzgf )
; rtDW . funlkrtj1r = 0 ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB .
ariy0mmiqe = rtDW . argr3txhnv ; } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID3 ( int_T tid ) { rtB . jjy1g5xce0 = rtP . Vg ; rtB . jpmk5wbcjk
= rtP . eee_Value ; rtB . hraw2xzx1x = rtP . gate_Value ; rtB . bljlccxajx =
rtP . qqq_Value ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
{ SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnUpdate ( rts , 0 ) ; if
( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { rtDW . argr3txhnv = rtB . ariy0mmiqe ; } UNUSED_PARAMETER ( tid
) ; } void MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
real_T * sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) ->
nld1v0c2kt [ 0 ] ; ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if
( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlProjection (
void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnProjection (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> d5spuwnbrf [ 0 ] ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } _rtZCSV -> mqnmsel1eh = ssGetT ( rtS ) - rtP . Step_Time ; _rtZCSV
-> oby1xcoxk5 = rtB . lnkhi50vct - rtP . Constant_Value ; _rtZCSV ->
phvpak2htt = rtB . lnkhi50vct - rtB . kj1zvpheax ; _rtZCSV -> kpecqdeacd =
rtB . b0fcxxvygu - rtP . HitCrossing_Offset ; if ( rtDW . funlkrtj1r == 0 ) {
_rtZCSV -> bgmcu5myqh = ( ( rtB . b0fcxxvygu - rtP . HitCrossing_Offset ) * (
real_T ) rtB . lbaw0ywzgf != 0.0 ) ; } else { _rtZCSV -> bgmcu5myqh = ssGetT
( rtS ) - ssGetTimeOfLastOutput ( rtS ) ; } } void MdlTerminate ( void ) { {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } }
static void mr_BOOst_mppt_cacheDataAsMxArray ( mxArray * destArray , mwIndex
i , int j , const void * srcData , size_t numBytes ) ; static void
mr_BOOst_mppt_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_BOOst_mppt_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_BOOst_mppt_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_BOOst_mppt_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_BOOst_mppt_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_BOOst_mppt_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) ; static uint_T
mr_BOOst_mppt_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_BOOst_mppt_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_BOOst_mppt_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_BOOst_mppt_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_BOOst_mppt_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_BOOst_mppt_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_BOOst_mppt_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_BOOst_mppt_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_BOOst_mppt_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_BOOst_mppt_GetDWork ( ) { static const char *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB )
, sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 8 ] = {
"rtDW.argr3txhnv" , "rtDW.egvifce2ld" , "rtDW.ob3vhelakn" , "rtDW.cyzctsgtgq"
, "rtDW.edbkmdbvou" , "rtDW.funlkrtj1r" , "rtDW.ig1xezdoi0" ,
"rtDW.pbqtcwhcnj" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 8
, rtdwDataFieldNames ) ; mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 0
, ( const void * ) & ( rtDW . argr3txhnv ) , sizeof ( rtDW . argr3txhnv ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . egvifce2ld ) , sizeof ( rtDW . egvifce2ld ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . ob3vhelakn ) , sizeof ( rtDW . ob3vhelakn ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . cyzctsgtgq ) , sizeof ( rtDW . cyzctsgtgq ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . edbkmdbvou ) , sizeof ( rtDW . edbkmdbvou ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . funlkrtj1r ) , sizeof ( rtDW . funlkrtj1r ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . ig1xezdoi0 ) , sizeof ( rtDW . ig1xezdoi0 ) ) ;
mr_BOOst_mppt_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . pbqtcwhcnj ) , sizeof ( rtDW . pbqtcwhcnj ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } mr_BOOst_mppt_cacheDataAsMxArray ( ssDW , 0 , 2
, ( const void * ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ; }
void mr_BOOst_mppt_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW .
argr3txhnv ) , rtdwData , 0 , 0 , sizeof ( rtDW . argr3txhnv ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . egvifce2ld ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . egvifce2ld ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . ob3vhelakn ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . ob3vhelakn ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . cyzctsgtgq ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . cyzctsgtgq ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . edbkmdbvou ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . edbkmdbvou ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . funlkrtj1r ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . funlkrtj1r ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . ig1xezdoi0 ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . ig1xezdoi0 ) ) ;
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtDW . pbqtcwhcnj ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . pbqtcwhcnj ) ) ; }
mr_BOOst_mppt_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW , 0
, 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_BOOst_mppt_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 3 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 3 ] = { "S-Function" , "Scope" , "S-Function" , } ; static
const char * blockPath [ 3 ] = {
"BOOst_mppt/powergui/EquivalentModel1/State-Space" , "BOOst_mppt/Scope" ,
"BOOst_mppt/powergui/EquivalentModel1/State-Space" , } ; static const int
reason [ 3 ] = { 0 , 0 , 2 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 3 ; ++ (
subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 ,
subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ]
] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 3 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 40 ) ;
ssSetNumBlockIO ( rtS , 16 ) ; ssSetNumBlockParams ( rtS , 666 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 5.0E-6 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2557054502U ) ; ssSetChecksumVal ( rtS , 1 ,
512478207U ) ; ssSetChecksumVal ( rtS , 2 , 2494288392U ) ; ssSetChecksumVal
( rtS , 3 , 1325535860U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
BOOst_mppt_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "BOOst_mppt" ) ;
ssSetPath ( rtS , "BOOst_mppt" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 20.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 3 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 3 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ,
"BOOst_mppt/PWM Generator\n(DC-DC)/Sawtooth\nGenerator/Model/Unit Delay" } ;
static const char_T * rt_LoggedStateNames [ ] = { "" , "DSTATE" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 0 }
; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . nld1v0c2kt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . argr3txhnv ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3
; static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 3 ] ; static real_T absTol [ 3 ] = { 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 3 ] = { 0U , 0U , 0U } ; static
real_T contStateJacPerturbBoundMinVec [ 3 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 3 ] ; static uint8_T zcAttributes [ 8 ] = {
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( 0x80 | ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) } ; { int i ; for ( i = 0 ; i < 3 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 5.0E-6
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode23tb" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 1 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 1 ) ; (
void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ;
ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 8 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 0 ) ;
ssSetSolverZcThreshold ( rtS , 0.001 ) ; ssSetSolverMaxConsecutiveMinStep (
rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS
, INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS )
; ssSetNumNonsampledZCs ( rtS , 8 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . nf4mt1cq5r = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal
( rtS , 0 , 2557054502U ) ; ssSetChecksumVal ( rtS , 1 , 512478207U ) ;
ssSetChecksumVal ( rtS , 2 , 2494288392U ) ; ssSetChecksumVal ( rtS , 3 ,
1325535860U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_BOOst_mppt_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_BOOst_mppt_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_BOOst_mppt_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } ssSetNumSFunctions ( rtS , 1 ) ;
{ static SimStruct childSFunctions [ 1 ] ; static SimStruct *
childSFunctionPtrs [ 1 ] ; ( void ) memset ( ( void * ) & childSFunctions [ 0
] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions ( rtS , &
childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS , 0 , & childSFunctions [ 0
] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T
sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [
1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ;
( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; static struct
_ssBlkInfoSLSize blkInfoSLSize ; ssSetBlkInfoSLSizePtr ( rts , &
blkInfoSLSize ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ;
ssSetAbsTolVector ( rts , ssGetAbsTolVector ( rtS ) + 0 ) ;
ssSetAbsTolControlVector ( rts , ssGetAbsTolControlVector ( rtS ) + 0 ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; static struct
_ssPortInputsSLSize inputPortInfoSLSize [ 2 ] ; rts -> blkInfo . blkInfo2 ->
blkInfoSLSize -> inputs = & inputPortInfoSLSize [ 0 ] ; { static struct
_ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits ( rts , &
inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 3 ] ; sfcnUPtrs [ 0 ] = & rtB . jjy1g5xce0 ;
sfcnUPtrs [ 1 ] = & rtB . jpmk5wbcjk ; sfcnUPtrs [ 2 ] = & rtB . bljlccxajx ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidthAsInt ( rts
, 0 , 3 ) ; } { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [ 0 ] = &
rtB . hraw2xzx1x ; sfcnUPtrs [ 1 ] = & rtB . pkqujry2qj ;
ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidthAsInt ( rts
, 1 , 2 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 2 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ; static struct
_ssPortOutputsSLSize outputPortInfoSLSize [ 2 ] ; rts -> blkInfo . blkInfo2
-> blkInfoSLSize -> outputs = & outputPortInfoSLSize [ 0 ] ;
_ssSetNumOutputPorts ( rts , 2 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 2 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
fwysot0tgt ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidthAsInt ( rts , 1 , 4 ) ; ssSetOutputPortSignal ( rts , 1 ,
( ( real_T * ) rtB . bw1ymovkkk ) ) ; } } ssSetContStates ( rts , & rtX .
nld1v0c2kt [ 0 ] ) ; ssSetContStateDisabled ( rts , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> nld1v0c2kt [ 0 ] ) ; { real_T * minVec =
& ( ( CXPtMin * ) ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ->
nld1v0c2kt [ 0 ] ; real_T * maxVec = & ( ( CXPtMax * )
ssGetJacobianPerturbationBoundsMaxVec ( rtS ) ) -> nld1v0c2kt [ 0 ] ;
ssSetJacobianPerturbationBoundsMinVec ( rts , minVec ) ;
ssSetJacobianPerturbationBoundsMaxVec ( rts , maxVec ) ; } ssSetModelName (
rts , "State-Space" ) ; ssSetPath ( rts ,
"BOOst_mppt/powergui/EquivalentModel1/State-Space" ) ; if ( ssGetRTModel (
rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 10 ] ; ssSetSFcnParamsCount ( rts , 10 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP .
StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP .
StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP .
StateSpace_P4_Size ) ; ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP .
StateSpace_P5_Size ) ; ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP .
StateSpace_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP .
StateSpace_P7_Size ) ; ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP .
StateSpace_P8_Size ) ; ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP .
StateSpace_P9_Size ) ; ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP .
StateSpace_P10_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . egvifce2ld
[ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . ob3vhelakn [ 0 ] ) ;
ssSetPWork ( rts , ( void * * ) & rtDW . kgui5h3axe [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 4 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 4 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 4 ) ;
ssSetDWorkWidthAsInt ( rts , 0 , 3 ) ; ssSetDWorkDataType ( rts , 0 ,
SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0
, & rtDW . cyzctsgtgq [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . egvifce2ld [ 0 ] ) ;
ssSetDWorkWidthAsInt ( rts , 2 , 23 ) ; ssSetDWorkDataType ( rts , 2 ,
SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork ( rts , 2
, & rtDW . ob3vhelakn [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 3 , 22 ) ;
ssSetDWorkDataType ( rts , 3 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
3 , 0 ) ; ssSetDWork ( rts , 3 , & rtDW . kgui5h3axe [ 0 ] ) ; }
ssSetModeVector ( rts , ( int_T * ) & rtDW . cyzctsgtgq [ 0 ] ) ;
sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCsAsInt ( rts , 3 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetInputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected (
rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
