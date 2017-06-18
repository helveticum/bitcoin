#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

HELVETICUMD=${HELVETICUMD:-$SRCDIR/helveticumd}
HELVETICUMCLI=${HELVETICUMCLI:-$SRCDIR/helveticum-cli}
HELVETICUMTX=${HELVETICUMTX:-$SRCDIR/helveticum-tx}
HELVETICUMQT=${HELVETICUMQT:-$SRCDIR/qt/helveticum-qt}

[ ! -x $HELVETICUMD ] && echo "$HELVETICUMD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($HELVETICUMCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for helveticumd if --version-string is not set,
# but has different outcomes for helveticum-qt and helveticum-cli.
echo "[COPYRIGHT]" > footer.h2m
$HELVETICUMD --version | sed -n '1!p' >> footer.h2m

for cmd in $HELVETICUMD $HELVETICUMCLI $HELVETICUMTX $HELVETICUMQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
