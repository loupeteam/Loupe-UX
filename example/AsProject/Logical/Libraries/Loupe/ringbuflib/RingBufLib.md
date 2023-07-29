![Automation Resources Group](http://automationresourcesgroup.com/images/arglogo254x54.png)

#RingBufLib
This library implements a Ring buffer. The user may add/remove items to the top or bottom of the buffer. 

Values can be retrieved by giving the index of the value relative to the top of the buffer. Index 0 corresponds to the top of the buffer.

If more values are added than there is memory allocated, the item furthest from the end which the new value is add, bottom or top, will be dropped from the buffer.

#Usage

##Create/Destroy

###BufferInit

####Description
This function allocates the necessary memory for the buffer. This must be called before any other **RingBufLib** functions are called in order to function correctly.

Calling **BufferInit()** on a buffer that has already been initialized, will deallocate the old buffer and allocate new memory.

####Input Parameters:
* **Buffer** - Pointer to the buffer
* **MaxValues** - Max number of entries
* **DataSize** - Size of each entry


####Return:	
* **Alloc Status** - Returns the status of the TMP_Alloc()
    
####Usage

    PROGRAM _INIT
       
       BufferInit(ADR(Buffer),MAX_BUFFERED_VALUES,SIZEOF(TempValue));
    
    END_PROGRAM

###BufferDestroy

####Description
This function deallocates memory used by a ring buffer. After a buffer is destroyed, it must be reinitialized before it can be used again.

####Input Parameters:
* **Buffer** - Pointer to the buffer

####Return:	
* **Buffer Status** - Status of the buffer or status of TMP_Free()
    
####Usage
    PROGRAM _EXIT

        //Deallocate memory that we were using
        BufferDestroy(ADR(Buffer));

    END_PROGRAM
    
##Enter/Remove Data

###BufferAddToBottom

####Description
This function will add a single item to the bottom of the buffer. The new item can be referenced using index **NumberValues - 1**.

####Input Parameters:
* **Buffer** - Pointer to the buffer
* **Data** - Pointer to the item to add

####Return:	
* **Buffer Status** - Returns the status of the buffer.
    
####Usage
    PROGRAM _CYCLIC
        
        //If we have new data, add it to the buffer
        IF newData THEN
            newData:= 0;
            
            //Populate the data
            Data.TimeStamp:= GetTimeStamp();
            
            //Add data to the buffer
            Status:= BufferAddToBottom(ADR(Buffer),ADR(Data));
            
            //Handle non-zero status
            IF Status <> 0 THEN
            
                Log(Status);
            
            END_IF
            
        END_IF
    
    END_PROGRAM

###BufferAddToTop

####Description
This function will add a single item to the top of the buffer. The new item can be referenced using index 0.

####Input Parameters:
* **Buffer** - Pointer to the buffer
* **Data** - Pointer to the item to add

####Return:	
* **Buffer Status** - Returns the status of the buffer.
    
####Usage
    PROGRAM _CYCLIC
        
        //If we have new data, add it to the buffer
        IF newData THEN
            newData:= 0;
            
            //Populate the data
            Data.TimeStamp:= GetTimeStamp();
            
            //Add data to the buffer
            Status:= BufferAddToTop(ADR(Buffer),ADR(Data));
            
            //Handle non-zero status
            IF Status <> 0 THEN
            
                Log(Status);
            
            END_IF
            
        END_IF
    
    END_PROGRAM

###BufferRemoveBottom

####Description
This function will remove a single item from the bottom of the buffer. The item removed will be **NumberValues - 1**.

####Input Parameters:
* **Buffer** - Pointer to the buffer

####Return:	
* **Buffer Status** - Returns the status of the buffer.
    
####Usage
    PROGRAM _CYCLIC
        
        //Check if we should remove the bottom item
        IF removeBottom THEN
            removeBottom:= 0;
            
            //Remove the last item in the buffer
            Status:= BufferRemoveBottom(ADR(Buffer));
            
            //Handle non-zero status
            IF Status <> 0 THEN
            
                Log(Status);
            
            END_IF
            
        END_IF
    
    END_PROGRAM
    
###BufferRemoveTop

####Description
This function will remove a single item from the top of the buffer. The item removed will be item 0.

####Input Parameters:
* **Buffer** - Pointer to the buffer

####Return:	
* **Buffer Status** - Returns the status of the buffer.
    
####Usage
    PROGRAM _CYCLIC
        
        //Check if we should remove the bottom item
        IF removeTop THEN
            removeTop:= 0;
            
            //Remove the first item in the buffer
            Status:= BufferRemoveTop(ADR(Buffer));
            
            //Handle non-zero status
            IF Status <> 0 THEN
            
                Log(Status);
            
            END_IF
            
        END_IF
    
    END_PROGRAM
    
###BufferClear

####Description
This function will remove all of the items in the buffer without the need to reinitialize.

####Input Parameters:
* **Buffer** - Pointer to the buffer

####Return:	
* **Buffer Status** - Returns the status of the buffer.
    
####Usage
    PROGRAM _CYCLIC
        
        //Check if we should remove the bottom item
        IF clearBuffer THEN
            clearBuffer:= 0;
            
            //Clear all items from the buffer
            Status:= BufferClear(ADR(Buffer));
            
            //Handle non-zero status
            IF Status <> 0 THEN
            
                Log(Status);
            
            END_IF
            
        END_IF
    
    END_PROGRAM
            
##Retrieve Data    
    
###BufferGetItemAdr

####Description
This function will return a pointer to the data specified by the parameters. It is recommended that you check for a valid address (Nonzero) and copy the data into local memory. 

**Warning:** Changing the data at the address will cause the buffer data to be updated and may cause undesired results if it is removed or overwritten while in use.

####Input Parameters:
* **Buffer** - Pointer to the buffer
* **Offset** - Item offset from the top of the buffer
* **Status** - Optional parameter. Pointer to a UINT to receive the status of the buffer.

####Return:	
* **Data** - Pointer to the requested data.
    
####Usage

 Use Data in place (*Less safe*)
    
    //Get the top item from the buffer
    MyData ACCESS BufferGetItemAdr(ADR(Buffer),0);
    
    //Check that the data is valid
    IF ADR(MyData) <> 0 THEN
        
        //Use Data
        BufferText:= MyData.Text;
        
    END_IF
    
Copy data for local use (*More safe*)
    
    //Get the top item from the buffer
    pMyData := BufferGetItemAdr(ADR(Buffer),0);
    
    //Check that the data is valid
    IF pMyData <> 0 THEN
        
        //Copy data for local use
        memcpy(ADR(MyData),pMyData,SIZEOF(MyData));
        
        //Use Data
        BufferText:= MyData.Text;
                        
    END_IF    


###BufferCopyItems

####Description
This function will copy **NumEntries** number of items starting from the **Offset** that is specified into the **Destination**.
####Input Parameters:
* **Buffer** - Pointer to the buffer
* **Offset** - Offset from the top of the buffer to start copying.
* **NumEntries** - Number of entries to copy.
* **Destination** - Destination to copy data into.
#####Optional    
* **Status** - Optional parameter. Pointer to a UINT to receive the status of the buffer.
                
####Return:	
* **Entries Copied** - Number of entries that were copied into the destination.
    
####Usage
    //Read the desired items
    NumItems:= BufferCopyItems(ADR(Buffer)
                ,TopValue
                ,MaxBufferSize
                ,ADR(MyDataArray)
                ,ADR(Status));

    //Check that the data is good    
    IF Status = 0 THEN

        //Loop through the items to use data
        FOR index:=0 to NumItems DO

            //Output each item
            OutputData(MyDataArray[index]);        

        END_FOR
            
    END_IF            