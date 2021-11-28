# Hello! This folder contains files from the https://github.com/id-Software/DOOM-3 repository.
They are used as examples of CERT C++ specification noncompliance.
(Examples may be a bit far fetched.) 

## First example - improper header define - https://github.com/id-Software/DOOM-3/blob/master/neo/idlib/math/Math.h
Broken rule: https://wiki.sei.cmu.edu/confluence/display/c/DCL37-C.+Do+not+declare+or+define+a+reserved+identifier
 
|   RULE   | SEVERITY | LIKELIHOOD | REMEDIATION COST | PRIORITY | LEVEL |
|   :---   | :------- | :--------- | :--------------- | :------- | :---- |
| DCL37-C  |   low    |  unlikely  |        low       |    P3    |  L3   |

## Second example - using std::rand - https://github.com/id-Software/DOOM-3/blob/master/neo/sys/win32/win_net.cpp
Broken rule: https://wiki.sei.cmu.edu/confluence/display/cplusplus/MSC50-CPP.+Do+not+use+std%3A%3Arand%28%29+for+generating+pseudorandom+numbers
 
|   RULE   | SEVERITY | LIKELIHOOD | REMEDIATION COST | PRIORITY | LEVEL |
|   :---   | :------- | :--------- | :--------------- | :------- | :---- |
|MSC50-CPP |  medium  |  unlikely  |       low        |    P6    |  L2   |

## Third example - not closing files properly - badfileio.cpp (custom file not associated with idSoftware and DOOM 3)
Broken rule: https://wiki.sei.cmu.edu/confluence/display/cplusplus/FIO51-CPP.+Close+files+when+they+are+no+longer+needed
 
|   RULE   | SEVERITY | LIKELIHOOD | REMEDIATION COST | PRIORITY | LEVEL |
|   :---   | :------- | :--------- | :--------------- | :------- | :---- |
|FIO51-CPP |  medium  |  unlikely  |     medium       |    P4    |  L3   |