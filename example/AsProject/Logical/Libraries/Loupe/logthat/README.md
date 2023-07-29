# Info

Library is provided by Loupe
https://loupe.team
info@loupe.team
1-800-240-7042

# Change log

- 0.05.1 - Rename problematic 'delete' internal var to 'deletion' (to avoid C++ keyword conflict in older AS versions)
- 0.05.0 - Remove constants: LOG_DEFAULT_MESSAGESIZE, LOG_DEFAULT_BUFFEREDENTRIES
    - Remove ManageLoggers Fn
    - Restricted formatted strings to size 320 chars
    - Changed message type from BRSE_ARL_Arguments_typ to StrExtArgs_typ 
    - Remove the max number of configurable loggers
    - Update to BR new logger system
- 0.04.1 - Add logStateChange() FUB.
- 0.04 - Change logger name strlen to 8 characters. 
   - Add logMessageData_typ as directly derived BRSE_ARL_Arguments_typ
- 0.03 - Increase default message size to handle ErrorLib messages by default
- 0.02 - Change internal ID handling to lessen the likelihood of ID collisions
- 0.01 - First version

# Documentation

Documentation for this and other Loupe libraries can be found at https://loupeteam.github.io/Sandbox/libraries.html
