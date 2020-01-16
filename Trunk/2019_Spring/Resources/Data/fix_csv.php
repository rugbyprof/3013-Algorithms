<?php

$data = file("./zip_codes_states.csv");
$fp = fopen("./cities.dat","w");
foreach($data as $line){
    $line = trim($line);
    list($z,$lat,$lon,$city,$state,$county) = explode(",",$line);
    $new = "{$z} {$lat} {$lon} \"{$city}\" \"{$state}\" \"{$county}\"\n";

    echo $new;
    fwrite($fp,$new);
}