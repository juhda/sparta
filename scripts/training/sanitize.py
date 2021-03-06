#-------------------------------------------------------------------------------
# Copyright (C) 2018 Tiago R. Muck <tmuck@uci.edu>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#-------------------------------------------------------------------------------

import sys
import argparse
import pandas as pd
from pathlib import Path
import numpy
from functools import reduce

parser = argparse.ArgumentParser(description='Generates a trace where each sample correspond to one ubench training combination')             
parser.add_argument('--srcfile', help='Source files to sanitize')
parser.add_argument('--destfile', help='Where to save the result')                  
args = parser.parse_args()


# Column used to search for boundaries between samples of different ubench combinations.
# There is an idle period between each combination, identified by samples with 0 instructions
# executed. We generate the aggregated sample for each combination by combining all samples
# between these idle periods
checkerCol = 'totalInstr'

# When aggregating we sumup the values of samples for most columns,
# except the ones listed here, which the mean value is taken
colsToAvg = ['busy_ips','freq_mhz','power_w','total_ips','util']

# These columns are handled separately
# sample_id is set by a separate counter
# timestamp is set to the current sum of total_time_s
specialCols = ['sample_id','timestamp','total_time_s']

# If any detected combination has less than this number of samples,
# ignore it
ignoreSampleCnt = 4


df = pd.read_csv(args.srcfile,sep=',',encoding='utf-8')
dfcols = list(df)
if len(dfcols) < (len(specialCols)+1):
    df = pd.read_csv(args.srcfile,sep=';',encoding='utf-8')
    dfcols = list(df)

#it will crash later for colums that are not number so we remove them now
for column in dfcols:
    try:            
        df[column].mean()       
    except:
        print('Ignoring column {}',column)
        df = df.drop(column, 1)

# These conditions are mandatory
assert(checkerCol in dfcols)
for s in specialCols:
    assert(s in dfcols)

currentId = 0
currentTimestamp = 0
currentSampleCnt = 0
currData = dict()

def addRow(row):
    global currentSampleCnt
    global currentTimestamp
    global dfcols
    global currData

    if row[checkerCol] == 0:
        return

    currentSampleCnt += 1
    for col in dfcols:
        if col not in currData:
            currData[col] = row[col]
        else:
            currData[col] += row[col]
        

def commitRow(row):
    global currentSampleCnt
    global currentTimestamp
    global dfcols
    global currData
    global currentId
    global sanitized_df

    if (row[checkerCol] != 0) or (currentSampleCnt == 0):
        return

    for col in dfcols:
        assert(col in currData)
        if col in colsToAvg:
            currData[col] /= currentSampleCnt

    if currentSampleCnt >= ignoreSampleCnt:
        currentTimestamp += currData['total_time_s']

        currData['timestamp'] = currentTimestamp
        currData['sample_id'] = currentId
    
        sanitized_df = sanitized_df.append(currData, ignore_index=True)
    
        currentId += 1
    else:
        print('{}: sample id {} has {} subsamples so will be ignored.'.format(args.srcfile,currentId,currentSampleCnt))
    
    currentSampleCnt = 0
    currData = dict()
    

sanitized_df = pd.DataFrame(columns=dfcols)

for index, row in df.iterrows():
    addRow(row)
    commitRow(row)

sanitized_df.to_csv(args.destfile, sep=';', encoding='utf-8',index=False)


