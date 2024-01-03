#ifndef RTW_HEADER_BOOst_mppt_h_
#define RTW_HEADER_BOOst_mppt_h_
#ifndef BOOst_mppt_COMMON_INCLUDES_
#define BOOst_mppt_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "BOOst_mppt_types.h"
#include <stddef.h>
#include "rt_zcfcn.h"
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME BOOst_mppt
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (16) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T fwysot0tgt ; real_T bw1ymovkkk [ 4 ] ; real_T
pq340nhst2 ; real_T kkianidgen ; real_T lnkhi50vct ; real_T lkoyo2evq0 ;
real_T hvqeao5zds ; real_T b0fcxxvygu ; real_T kj1zvpheax ; real_T pkqujry2qj
; real_T ariy0mmiqe ; real_T jjy1g5xce0 ; real_T jpmk5wbcjk ; real_T
hraw2xzx1x ; real_T bljlccxajx ; boolean_T lbaw0ywzgf ; } B ; typedef struct
{ real_T argr3txhnv ; real_T egvifce2ld [ 2 ] ; void * kgui5h3axe [ 22 ] ;
struct { void * LoggedData ; } nvd2ol0qok ; int_T ob3vhelakn [ 23 ] ; int_T
cyzctsgtgq [ 3 ] ; int_T edbkmdbvou ; int_T funlkrtj1r ; boolean_T ig1xezdoi0
; boolean_T pbqtcwhcnj ; } DW ; typedef struct { real_T nld1v0c2kt [ 3 ] ; }
X ; typedef struct { real_T nld1v0c2kt [ 3 ] ; } XDot ; typedef struct {
boolean_T nld1v0c2kt [ 3 ] ; } XDis ; typedef struct { real_T nld1v0c2kt [ 3
] ; } CStateAbsTol ; typedef struct { real_T nld1v0c2kt [ 3 ] ; } CXPtMin ;
typedef struct { real_T nld1v0c2kt [ 3 ] ; } CXPtMax ; typedef struct {
real_T d5spuwnbrf [ 3 ] ; real_T mqnmsel1eh ; real_T oby1xcoxk5 ; real_T
phvpak2htt ; real_T kpecqdeacd ; real_T bgmcu5myqh ; } ZCV ; typedef struct {
ZCSigState nf4mt1cq5r ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T Vg ; real_T Constant_Value ; real_T
StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 102 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3 [ 3 ] ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 510 ] ; real_T
StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 4 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 [ 2 ] ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 [ 2 ] ; real_T
StateSpace_P8_Size [ 2 ] ; real_T StateSpace_P8 [ 2 ] ; real_T
StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ; real_T StateSpace_P10_Size
[ 2 ] ; real_T StateSpace_P10 ; real_T donotdeletethisgain_Gain ; real_T
Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T Gain_Gain ; real_T
Constant4_Value ; real_T Constant2_Value ; real_T uib2_Gain ; real_T
HitCrossing_Offset ; real_T UnitDelay_InitialCondition ; real_T eee_Value ;
real_T gate_Value ; real_T qqq_Value ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_BOOst_mppt_GetDWork ( ) ; extern void mr_BOOst_mppt_SetDWork ( const
mxArray * ssDW ) ; extern mxArray * mr_BOOst_mppt_GetSimStateDisallowedBlocks
( ) ; extern const rtwCAPI_ModelMappingStaticInfo *
BOOst_mppt_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
