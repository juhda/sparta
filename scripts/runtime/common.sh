######################################################
# This script provides common definitions for the
# other runtime scripts
######################################################

######################################################
# Extracts the script folder from the current script
######################################################
__SOURCE="${BASH_SOURCE[0]}"
while [ -h "$__SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  __DIR="$( cd -P "$( dirname "$__SOURCE" )" && pwd )"
  __SOURCE="$(readlink "$__SOURCE")"
  [[ $__SOURCE != /* ]] && __SOURCE="$__DIR/$__SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
SCRIPTDIR="$( cd -P "$( dirname "$__SOURCE" )" && cd .. && pwd )"

######################################################
# Checks if the conf file exists. If it does
# not, creates one with default information at
# scripts/runtime/runtime_conf.sh
# Edit the generated file with the correct remote host
# info
######################################################
__RTS_CONF=$SCRIPTDIR/runtime/runtime_conf.sh
__RTS_CONFDEFAULT=$SCRIPTDIR/runtime/.runtime_conf.sh
if [ -e $__RTS_CONF ]
then
    source $__RTS_CONF
else
    echo "$__RTS_CONF not found. Creating default file..."
    cp $__RTS_CONFDEFAULT $__RTS_CONF
    echo "Please edit $__RTS_CONF with your remote host info and rerun this script"
    exit
fi


######################################################
# Common definitions
######################################################

# our the root dir
RTS_ROOT=$(readlink -f $SCRIPTDIR/..)

# binaries path
RTS_BIN_DIR_NAME="bin_"$RTS_ARCH"_"$RTS_PLAT
RTS_BINS_PATH=$RTS_ROOT/$RTS_BIN_DIR_NAME

# path and name of the kernel sensing module
RTS_MODULE_NAME=vitamins
RTS_MODULE_PATH=$RTS_BINS_PATH/sensing_module/$RTS_MODULE_NAME.ko

# directory where the daemon will dump output
RTS_DAEMON_OUTDIR=$RTS_ROOT/outdir

# directory where the daemons binaries are
RTS_DAEMON_BIN_DIR=$RTS_BINS_PATH/daemons

# file used to indicate to the stop script that
# a daemon is running. Stores the pid of the
# daemon when running
RTS_DAEMON_PID=$RTS_DAEMON_BIN_DIR/.current_active_daemon.pid

echo SCRIPTDIR=$SCRIPTDIR
echo RTS_ROOT=$RTS_ROOT
echo RTS_BINS_PATH=$RTS_BINS_PATH
echo RTS_MODULE_NAME=$RTS_MODULE_NAME
echo RTS_MODULE_PATH=$RTS_MODULE_PATH
echo RTS_DAEMON_OUTDIR=$RTS_DAEMON_OUTDIR
echo RTS_DAEMON_BIN_DIR=$RTS_DAEMON_BIN_DIR
echo RTS_DAEMON_PID=$RTS_DAEMON_PID

######################################################
# Helper functions
######################################################


# Searches for active daemon processes and kills them

function RTS_SEEK_DAEMONS_AND_KILL(){

    # Searches for processes whose name matches a
    # binary at $RTS_DAEMON_BIN_DIR and kill it 
    # if it has $RTS_BINS_PATH in its path

    daemons_bin_files=$(ls $RTS_DAEMON_BIN_DIR 2>/dev/null | xargs)
    for dbin in $daemons_bin_files; do
        daemon_pid=$(pgrep -x -U $(id -ur) $dbin)
        daemon_path=$(find /proc/$daemon_pid/exe -printf "%l\n" 2>/dev/null)
        if [[ $daemon_path == *"$RTS_BIN_DIR_NAME"* ]]; then
          echo "Match"
          kill -9 $daemon_pid
        fi
    done
}
export -f RTS_SEEK_DAEMONS_AND_KILL

