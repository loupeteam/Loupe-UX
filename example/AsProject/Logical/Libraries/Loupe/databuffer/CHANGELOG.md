0.01.1 - Changed AppendToBuffer() behavior if data does not fit entirely in buffer.
			Previously, no data was added to the buffer.
			Now, the buffer will be filled with the beginning of the data.
			The same status will be returned as before.

0.01 - First version. Includes datbufInitBuffer(), datbufClearBuffer(), and datbufAppendToBuffer().
