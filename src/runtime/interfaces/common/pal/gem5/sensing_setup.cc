/*******************************************************************************
 * Copyright (C) 2018 Tiago R. Muck <tmuck@uci.edu>
 * Copyright (C) 2018 Bryan Donyanavard <bdonyana@uci.edu>
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

#include <runtime/interfaces/common/pal/sensing_setup.h>
#include <runtime/interfaces/sensing_module.h>


template<>
void pal_sensing_setup<SensingModule>(SensingModule *m){
    // no sensors implemented yet
}

template<>
void pal_sensing_teardown<SensingModule>(SensingModule *m){
    // no sensors implemented yet
}

/*
 * Sensing interface functions implementation
 */

template<>
typename SensingTypeInfo<SEN_POWER_W>::ValType
SensingInterface::sense<SEN_POWER_W,power_domain_info_t>(const power_domain_info_t *rsc, int wid)
{
	return 0;
}

template<>
typename SensingTypeInfo<SEN_POWER_W>::ValType
SensingInterface::senseAgg<SEN_POWER_W,power_domain_info_t>(const power_domain_info_t *rsc, int wid)
{
	return 0;
}
