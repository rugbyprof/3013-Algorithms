<?php

$data = json_decode(file_get_contents("top_1000_cities.json"),true);

print_r($data);
/*
[999] => Array
(
    [city] => Panama City
    [growth_from_2000_to_2013] => 0.1%
    [latitude] => 30.1588129
    [longitude] => -85.6602058
    [population] => 36877
    [rank] => 1000
    [state] => Florida
)
*/

$fp = fopen("alter_top_1000_cities.csv","w");

foreach($data as $c){
  $c['growth_from_2000_to_2013'] = trim($c['growth_from_2000_to_2013'],"%");
  fwrite($fp,"{$c['city']},{$c['growth_from_2000_to_2013']},{$c['latitude']},{$c['longitude']},{$c['population']},{$c['rank']},{$c['state']}\n");
}