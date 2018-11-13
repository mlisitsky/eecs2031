#!/bin/bash

for (( ; ; ))
do
if (($1 & 1))
	then gpio write 1 1
fi

if (($1>>1 &1))
	then gpio write 2 1
fi

if (($1>>2 &1))
	then gpio write 3 1
fi

if (($1>>3 &1))
	then gpio write 4 1
fi
done
