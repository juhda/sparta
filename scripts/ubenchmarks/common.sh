# Includes the confs
source $SPARTA_SCRIPTDIR/confs.sh

#Defs for the uBenchmarks

HIGHIPC_HIGHLOAD="0 4096 0"
HIGHIPC_MIDLOAD="5000 125644 0"
HIGHIPC_LOWLOAD="10000 25000 0"
LOWIPC_HIGHLOAD1="0 512 1"
LOWIPC_HIGHLOAD2="0 1024 2"
LOWIPC_MIDLOAD1="5000 6000 1"
LOWIPC_MIDLOAD2="5000 28603 2"
LOWIPC_LOWLOAD1="10000 1250 1"
LOWIPC_LOWLOAD2="10000 6000 2"

P_HIGHIPC_HIGHLOAD="100000  0 4096 0"
P_HIGHIPC_MIDLOAD="1000     5000 125644 0"
P_HIGHIPC_LOWLOAD="1000     10000 25000 0"
P_LOWIPC_HIGHLOAD1="10000   0 512 1"
P_LOWIPC_HIGHLOAD2="80000   0 1024 2"
P_LOWIPC_MIDLOAD1="1000     5000 6000 1"
P_LOWIPC_MIDLOAD2="1000     5000 28603 2"
P_LOWIPC_LOWLOAD1="1000     10000 1250 1"
P_LOWIPC_LOWLOAD2="1000     10000 6000 2"

# Path to binaries
UBENCH_BIN_DIR=$SPARTA_ROOT/"bin_"$RTS_ARCH"_"$RTS_PLAT/ubenchmarks
