# Hello this folder contains files from the https://github.com/id-Software/DOOM-3 repository
They are used as an example for CERT c++ specification noncompliance.
That being said what we've managed to find is quite far fetched 

## first example is of header https://github.com/id-Software/DOOM-3/blob/master/neo/idlib/math/Math.h
 breaking https://wiki.sei.cmu.edu/confluence/display/c/DCL37-C.+Do+not+declare+or+define+a+reserved+identifier
 include guard shouldn't begin and and with underscores 
 RULE       SEVERITY        LIKELIHOOD      REMEDIATION COST        PRIORITY        LEVEL
 DCL37-C        low          unlikely               low                P3             L3

## second example is using rand() in https://github.com/id-Software/DOOM-3/blob/master/neo/sys/win32/win_net.cpp
breaking https://wiki.sei.cmu.edu/confluence/display/cplusplus/MSC50-CPP.+Do+not+use+std%3A%3Arand%28%29+for+generating+pseudorandom+numbers
 RULE       SEVERITY        LIKELIHOOD      REMEDIATION COST        PRIORITY        LEVEL
 MSC50-CPP     medium          unlikely               low                P6             L2

## third example has nothing to do with idSoftware and DOOM 3  but  it's badfileio.cpp
breaking https://wiki.sei.cmu.edu/confluence/display/cplusplus/FIO51-CPP.+Close+files+when+they+are+no+longer+needed
 RULE       SEVERITY        LIKELIHOOD      REMEDIATION COST        PRIORITY        LEVEL
 FIO51-CPP    medium         unlikely               medium              p4             l3