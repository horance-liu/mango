#ifndef H30D7660B_2275_4CEB_B32B_AD165085201D
#define H30D7660B_2275_4CEB_B32B_AD165085201D

#include <mango/dsl/step/StepRegistration.h>
#include <mango/core/model/Table.h>

////////////////////////////////////////////////////////////////////////////////
#define STEPS(prefix) __DEF_STPES(prefix##Steps, __COUNTER__)

////////////////////////////////////////////////////////////////////////////////
#define GIVEN __STEP
#define WHEN  __STEP
#define THEN  __STEP

////////////////////////////////////////////////////////////////////////////////
#define __PARAM_N(type, name, n) const auto name = args.getArgAt<type>(n)

////////////////////////////////////////////////////////////////////////////////
#define PARAM_0(type, name) __PARAM_N(type, name, 0)
#define PARAM_1(type, name) __PARAM_N(type, name, 1)
#define PARAM_2(type, name) __PARAM_N(type, name, 2)
#define PARAM_3(type, name) __PARAM_N(type, name, 3)
#define PARAM_4(type, name) __PARAM_N(type, name, 4)
#define PARAM_5(type, name) __PARAM_N(type, name, 5)

////////////////////////////////////////////////////////////////////////////////
#define TABLE(name) const auto& name = args.getTable()

#endif
