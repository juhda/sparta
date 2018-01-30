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

#include "../pal_setup.h"

#include <core/core.h>


core_arch_t pal_core_arch(int core)
{
    arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}

bool pal_arch_has_freq(core_arch_t arch, core_freq_t freq)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}

void pal_setup_freq_domains_info(sys_info_t *sys)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}

void pal_setup_power_domains_info(sys_info_t *sys)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}


freq_domain_info_t * pal_core_freq_domain(int core)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}

power_domain_info_t * pal_core_power_domain(int core)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}


void model_setup_freq_domains(sys_info_t *sys)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}

void model_setup_power_domains(sys_info_t *sys)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}


void model_setup_overheads(model_sys_t *sys)
{
	arm_throw(UnimplementedException,"Funciton not implemented: %s",__PRETTY_FUNCTION__);
}

