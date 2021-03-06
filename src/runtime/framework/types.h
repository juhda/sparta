/*******************************************************************************
 * Copyright (C) 2018 Tiago R. Muck <tmuck@uci.edu>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#ifndef __arm_rt_actutation_types_h
#define __arm_rt_actutation_types_h

#include <core/core.h>
#include <runtime/interfaces/common/perfcnts.h>

//////////////////////////////////////////////////////////////////////////////
// This struct should be reviewed. Proably need to get rid of this "modes".
// If a system actuator need to be consiedered by the models, its model
// should be registered explicitly.
enum ActuationMode {
	//actuation values are set by the framework
	ACTMODE_FRAMEWORK = 0,

	//actuation values are set by the system (linux)
	//the framework should include model of the system policy used
	ACTMODE_SYSTEM,
	//////////////////////////
	//////////////////////////
	SIZE_ACTMODE
};
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Actuation knob types
enum ActuationType {
	ACT_NULL = 0,
	ACT_FREQ_MHZ,
	ACT_ACTIVE_CORES,
	//////////////////////////
	//////////////////////////
	SIZE_ACT_TYPES
};

// This struct has information
// describing each actuation knob type.
// Some default information is provided, but
// this struct should be specialized for every
// knob type.
template <ActuationType T>
struct ActuationTypeInfo {
	//the data type of the actuation knob value
	using ValType = double;
};
//of course this template instantiation is invalid
template <> struct ActuationTypeInfo<SIZE_ACT_TYPES>;

//Now the knob types values specializations

template <> struct ActuationTypeInfo<ACT_FREQ_MHZ>{
    using ValType = int; //integer value in MHz
};

template <> struct ActuationTypeInfo<ACT_ACTIVE_CORES>{
    using ValType = int;
};

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Sensing data types
enum SensingType {
    //Performance stuff
	SEN_PERFCNT = 0,
	SEN_TOTALTIME_S,
	SEN_BUSYTIME_S,
	SEN_NIVCSW,
	SEN_NVCSW,
	SEN_BEATS,
	SEN_FREQ_MHZ,
	SEN_LASTCPU,

	//Other sensing data
	SEN_POWER_W,
	SEN_TEMP_C,

	/////////////
	SIZE_SEN_TYPES
};


// This struct has information
// describing each sensinng type.
// Some default information is provided, but
// this struct should be specialized type.
template <SensingType T>
struct SensingTypeInfo {
    // The data type of the sensing value
    // Default is double
    using ValType = double;

    // ParamType. Used by SEN_PERFCNT to
    // specify which counter we are reading,
    // and by SEN_BEATS to specify beats domain.
    // For most SEN_* this won't be used and
    // is void
    using ParamType = void;
};
//of course this template instantiation is invalid
template <> struct SensingTypeInfo<SIZE_SEN_TYPES>;

//Now the knob types values specializations

template <> struct SensingTypeInfo<SEN_PERFCNT>{
    using ValType = uint64_t; //number of events
    using ParamType = perfcnt_t; //which perf. counter
};

template <> struct SensingTypeInfo<SEN_TOTALTIME_S>{
    using ValType = double; // total time elapsed in s
    using ParamType = void;
};

template <> struct SensingTypeInfo<SEN_BUSYTIME_S>{
    using ValType = double; // total time the cpu was busy in s
    using ParamType = void;
};

template <> struct SensingTypeInfo<SEN_BEATS>{
    using ValType = unsigned int; // number of heartbeats issued
    using ParamType = unsigned int; //beats domain
};

template <> struct SensingTypeInfo<SEN_NIVCSW>{
    using ValType = unsigned int; // number of involuntary ctx switches
    using ParamType = void;
};
template <> struct SensingTypeInfo<SEN_NVCSW>{
    using ValType = unsigned int; // number of voluntary ctx switches
    using ParamType = void;
};

template <> struct SensingTypeInfo<SEN_POWER_W>{
    using ValType = double; // average power in W
    using ParamType = void;
};

template <> struct SensingTypeInfo<SEN_TEMP_C>{
    using ValType = double; // average temperature in C
    using ParamType = void;
};

template <> struct SensingTypeInfo<SEN_FREQ_MHZ>{
    using ValType = double; // average frequency in MHz
    using ParamType = void;
};

template <> struct SensingTypeInfo<SEN_LASTCPU>{
    using ValType = int; //last cpu used by some task
    using ParamType = void;
};


#endif

