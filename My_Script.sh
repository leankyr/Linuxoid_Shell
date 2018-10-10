#!/bin/bash

#My first script 





#echo "First Arg is  "
#echo $1

#-----------------------------------------------------------------------------------#

if [[ $1 == ""  ]]
then

    echo "Hello World!"
# gcc test.c
    flag=true
    touch com.txt
    while ( $flag ) 
    do 

          echo -n  "Kyriazis_7711>"
          read command 


#echo -n "the command is "
          echo  $command > com.txt


          what=$(grep -c quit com.txt) 

          if [[ $what>0 ]] 
          then

              flag=false

          fi

          ./a.out $command

    done
#---------------------------------------------------------------------------------------#
else 
touch com.txt
echo "Batch Mode" 
flag=false


cat $1



while IFS='' read -r line || [[ -n "$line" ]]; do
    echo  $line>com.txt  

    what=$(grep -c quit com.txt) 
    # echo "what is: $what"

    if [[ $what>0 ]]
     then

         flag=true

    fi
    ./a.out $line 
done < "$1"  

if  ($flag)
then 
  
   echo  "quit was encountered"
 fi

fi


