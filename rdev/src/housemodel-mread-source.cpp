// Source MD5: 50a84b3b28654f1c3497e9bfede27cf0

#include "modelheader.h"

// DEFS:
#define INITFUN___ _model_housemodel_main__
#define ODEFUN___ _model_housemodel_ode__
#define TABLECODE___ _model_housemodel_table__
#define CONFIGFUN___ _model_housemodel_config__
#define _nEQ 3
#define _nPAR 13
#define N_GUT 1
#define F_GUT _F_[0]
#define ALAG_GUT _ALAG_[0]
#define R_GUT _R_[0]
#define D_GUT _D_[0]
#define GUT _A_[0]
#define CENT _A_[1]
#define RESP _A_[2]
#define GUT_0 _A_0_[0]
#define CENT_0 _A_0_[1]
#define RESP_0 _A_0_[2]
#define dxdt_GUT _DADT_[0]
#define dxdt_CENT _DADT_[1]
#define dxdt_RESP _DADT_[2]
#define CL _THETA_[0]
#define VC _THETA_[1]
#define KA _THETA_[2]
#define F1 _THETA_[3]
#define WT _THETA_[4]
#define SEX _THETA_[5]
#define WTCL _THETA_[6]
#define WTVC _THETA_[7]
#define SEXCL _THETA_[8]
#define SEXVC _THETA_[9]
#define KIN _THETA_[10]
#define KOUT _THETA_[11]
#define IC50 _THETA_[12]

// FIXED:
// No fixed parameters.

// INCLUDES:

// GLOBAL CODE BLOCK:
#define CP (CENT/hm::VCi)
#define INH (CP/(IC50+CP))
typedef double localdouble;
namespace hm {
  localdouble CLi = 0;
  localdouble VCi = 0;
  localdouble KAi = 0;
  localdouble KOUTi = 0;
  localdouble lWT = 0;
}
double DV;
typedef double localdouble;
typedef int localint;
typedef bool localbool;

// CONFIG CODE BLOCK:
BEGIN_config
END_config

// MAIN CODE BLOCK:
BEGIN_main
F_GUT = F1;
hm::CLi   = exp(log(CL)   + WTCL*log(WT/70) + log(SEXCL)*SEX + ETA(1));
hm::VCi   = exp(log(VC)   + WTVC*log(WT/70) + log(SEXVC)*SEX + ETA(2));
hm::KAi   = exp(log(KA)   + ETA(3));
hm::KOUTi = exp(log(KOUT) + ETA(4));
RESP_0 = KIN/hm::KOUTi;
END_main

// DIFFERENTIAL EQUATIONS:
BEGIN_ode
dxdt_GUT = -hm::KAi*GUT;
dxdt_CENT = hm::KAi*GUT - (hm::CLi/hm::VCi)*CENT;
dxdt_RESP = KIN*(1-INH) - hm::KOUTi*RESP;
END_ode

// TABLE CODE BLOCK:
BEGIN_table
DV = CP*exp(EPS(1));
_capture_[0] = DV;
_capture_[1] = CP;
END_table
