### Authors 
- Jan Wieczorek 21024
- Tymoteusz Urbanowicz 20149

# Short ZAP report summary

### WebGoat - Zap traditional spider
| Name | CWE ID | Risk level | OWASP TOP 10 2021 name | OWASP TOP 10 2021 ID | CWE category id
|---|---|---|---|---|---|
|SQL Injection | 89 | HIGH | Injection | A03:2021 | 1347 |
| Parameter tampering | 472 | MEDIUM | Insecure design | A04:2021 | 1348 |
| Absence of Anti-CSRF Token | 352 | LOW | Broken Access Control | A01:2021 | 1345 |
| Cookie No HttpOnly Flag | 1004 | LOW | Security Misconfiguration | A05:2021 | 1349 |
| Cookie without SameSite Attribute | 1275 | LOW | Broken Access Control | A01:2021 | 1345 |
| Timestam Disclosure - Unix | 200 | LOW | Broken Access Control | A01:2021 | 1345 |
| Loosely Scoped Cookie | 565 | Informational | Software and Data Integrity Failures | A08:2021 | 1354 |

### Damn small vulnerable web - Zap traditional spider
| Name | CWE ID | Risk level | OWASP TOP 10 2021 name | OWASP TOP 10 2021 ID | CWE category id
|---|---|---|---|---|---|
| Cross Site Scripting | 79 | HIGH | Injection | A03:2021 | 1347 |
| External Redirect | 601 | HIGH | Broken Access Control | A01:2021 | 1345 |
| Path Traversal | 22 | HIGH | Broken Access Control | A01:2021 | 1345 |
| SQL Injection - SQLite | 89 | HIGH | Injection | A03:2021 | 1347 |
| Buffer Overflow | 120 | MEDIUM | not present in 2021 top 10 |    |    |
| X-Frame-Options Header Not Set | 1021 | MEDIUM | Insecure Design | A04:2021 | 1348 |
| Absence of Anti-CSRF Token | 352 | LOW | Broken Access Control | A01:2021 | 1345 |
| Application Error Disclosure | 200 | LOW | Broken Access Control | A01:2021 | 1345 |
| Timestamp Disclosure - Unix | 200 | LOW | Broken Access Control | A01:2021 | 1345 |
| X-Content-Type-Options Header Missing | 693 | LOW | not present in 2021 top 10 |    |    |
| Inf. Disclosure - Sensitive Information in URL | 200 | Informational | Broken Access Control | A01:2021 | 1345 |
| Inf. Disclosure - Suspicious Comments | 200 | Informational | Broken Access Control | A01:2021 | 1345 |

### WebGoat - Zap ajax spider (Firefox Headless)
| Name | CWE ID | Risk level | OWASP TOP 10 2021 name | OWASP TOP 10 2021 ID | CWE category id
|---|---|---|---|---|---|
| Parameter Tampering | 472 | MEDIUM | Insecure Design | A04:2021 | 1348 |
| Absence of Anti-CSRF Tokens | 352 | LOW | Broken Access Control | A01:2021 | 1345 |
| Cookie No HttpOnly Flag | 1004 | LOW | Security Misconfiguration | A05:2021 | 1349 |
| Cookie without SameSite Attribute | 1275 | LOW | Broken Access Control | A01:2021 | 1345 |
| Timestamp Disclosure - Unix | 200 | LOW | Broken Access Control | A01:2021 | 1345 |

### Damn small vulnerable web - Zap ajax spider (Firefox Headless)
| Name | CWE ID | Risk level | OWASP TOP 10 2021 name | OWASP TOP 10 2021 ID | CWE category id
|---|---|---|---|---|---|
| Cross Site Scripting (Reflected) | 79 | HIGH | Injection | A03:2021 | 1347 |
| External Redirect | 601 | HIGH | Broken Access Control | A01:2021 | 1345 |
| Path Traversal | 22 | HIGH | Broken Access Control | A01:2021 | 1345 |
| Remote File Inclusion | 98 | HIGH | Injection | A03:2021 | 1347 |
| SQL Injection - SQLite | 89 | HIGH | Injection | A03:2021 | 1347 |
| Buffer Overflow | 120 | MEDIUM | not present in 2021 top 10 |    |    | 
| Missing Anti-clickjacking Header | 1021 | MEDIUM | Insecure Design | A04:2021 | 1348 |
| Absence of Anti-CSRF Tokens | 352 | LOW | Broken Access Control | A01:2021 | 1345 |
| Application Error Disclosure | 200 | LOW | Broken Access Control | A01:2021 | 1345 |
| Private IP Disclosure | 200 | LOW | Broken Access Control | A01:2021 | 1345 |
| Timestamp Disclosure - Unix | 200 | LOW | Broken Access Control | A01:2021 | 1345 |
| X-Content-Type-Options Header Missing | 693 | LOW | not present in 2021 top 10 |    |    | 
| Information Disclosure - Sensitive Information in URL | 200 | Informational | Broken Access Control | A01:2021 | 1345 |
| Information Disclosure - Suspicious Comments | 200 | Informational | Broken Access Control | A01:2021 | 1345  |
