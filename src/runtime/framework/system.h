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

#ifndef __arm_rt_system_h
#define __arm_rt_system_h

#include <core/core.h>

#include <runtime/interfaces/window_manager.h>
#include <runtime/common/reports.h>
#include <runtime/interfaces/performance_data.h>

#include "actuation_interface.h"
#include "sensing_interface.h"

class System : public ActuationInterface, public SensingInterface {
  private:
	//used to check only one system object should exist
	static bool _system_created;

	sys_info_t _sys_info;
	core_info_t _core_info_list[MAX_NR_CPUS];

	void _init_info();
	void _init_info(simulation_t *sim);
	void _sensing_setup_common();

	int _system_pid;
	std::string _system_ready_file;

  protected:

	SensingWindowManager *_manager;

	System();
	System(simulation_t *sim);

	/*
	 * Called by System::start()
	 * You must implement this in order to setup your sensing windows
	 */
	virtual void setup() = 0;

	/*
	 * Called by System::stop() at the end
	 * Override to print execution repots and/or dump files with data
	 */
	virtual void report() {};

  protected:
	void quit();

  public:
	virtual ~System();

	void start();
	void stop();

	sys_info_t* info() { return &_sys_info;}
	virtual model_sys_t* model() {return nullptr;}

	SensingModule *sensingModule() { return _manager->sensingModule(); }
	SensingWindowManager *windowManager() { return _manager; }
	const PerformanceData& sensedData() { return sensingModule()->data(); }

};

#endif

