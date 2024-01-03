#include "BOOst_mppt_capi_host.h"
static BOOst_mppt_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        BOOst_mppt_host_InitializeDataMapInfo(&(root), "BOOst_mppt");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
