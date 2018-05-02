<?php

// NOT DONE
$handle = @fopen("roads.geojson", "r");
if ($handle) {
    while (($buffer = fgets($handle, 4096)) !== false) {
        if(strpos($buffer,"Major Highway")){
            // $name = 
            // $line = strstr($buffer,"coordinates");
            // $line = str_replace("coordinates\":","",$line);
            // $line = str_replace(",","",$line);
            // $line = str_replace("} }","",$line);
            // echo"$line\n";
            //$buffer = str_replace("},","",$buffer);
            $buffer = trim($buffer,",");
            $buffer = substr($buffer,0,strlen($buffer)-1);
            $buffer = substr($buffer,0,strlen($buffer)-1);
            print_r($buffer);
            echo"\n";
            echo"\n";

        }
    }
    if (!feof($handle)) {
        echo "Error: unexpected fgets() fail\n";
    }
    fclose($handle);
}

