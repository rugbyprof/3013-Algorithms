<?php

$data = file_get_contents("cities.json");

$json = json_decode($data,true);

print_r($json);

$fixed = [];

foreach($json as $key => $row){
    $row['population'] = $row['population'] * 1;
    $row['rank'] = $row['rank'] * 1;
    $row['growth_from_2000_to_2013'] = trim($row['growth_from_2000_to_2013'],"%");
    $row['growth_from_2000_to_2013'] = $row['growth_from_2000_to_2013'] * 1;
    $fixed[$key] = $row;
}

file_put_contents("fixed.json",json_encode($fixed));