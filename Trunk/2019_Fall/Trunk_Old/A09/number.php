<?php

$data = file("multi.md");

$count = 1;

foreach($data as $row){
    if (preg_match('/__*\)__/',$row, $matches)) {
       print_r($matches);
      }
}