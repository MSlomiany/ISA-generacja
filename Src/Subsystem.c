/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Jun 16 21:50:13 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Model step function */
void Subsystem_step(RT_MODEL_Subsystem_T *const Subsystem_M, real_T
                    *Subsystem_Y_Output)
{
  real_T u0;
  int32_T tmp;

  /* Step: '<S3>/Step' incorporates:
   *  DigitalClock: '<S3>/Digital Clock'
   */
  u0 = ((Subsystem_M->Timing.clockTick0) * 0.05);
  if (u0 < 0.0) {
    tmp = 0;
  } else {
    tmp = -100;
  }

  /* End of Step: '<S3>/Step' */

  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S3>/Product'
   */
  u0 = (real_T)tmp * u0 + 101324.0;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 101325.0) {
    u0 = 101325.0;
  } else {
    if (u0 < 70000.0) {
      u0 = 70000.0;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Outport: '<Root>/Output' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  MATLAB Function: '<S1>/altitudeCalculation'
   */
  *Subsystem_Y_Output = ((1.0 - pow(u0 / 101325.0, 0.19025875190258751)) *
    44300.0 >= 100.0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Subsystem_M->Timing.clockTick0++;
  UNUSED_PARAMETER(Subsystem_M);
}

/* Model initialize function */
void Subsystem_initialize(RT_MODEL_Subsystem_T *const Subsystem_M, real_T
  *Subsystem_Y_Output)
{
  /* Registration code */

  /* external outputs */
  (*Subsystem_Y_Output) = 0.0;
  UNUSED_PARAMETER(Subsystem_M);
}

/* Model terminate function */
void Subsystem_terminate(RT_MODEL_Subsystem_T *const Subsystem_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(Subsystem_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
