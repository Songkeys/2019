<?php

$input = file('./06.txt', FILE_IGNORE_NEW_LINES);

$orbits1 = array();
$orbits2 = array();
foreach ($input as $line) {
	[$p, $c] = explode(')', $line);
	if (!$orbits1[$p]) $orbits1[$p] = [];
	$orbits1[$p][] = $c;
	$orbits2[$c] = $p;
}

/* part 1 */
$part1 = 0;
function findChildren($p, $level = 0) {
	global $orbits1, $part1;
	$part1 += $level;
	if ($orbits1[$p]) {
		foreach ($orbits1[$p] as $c) {
			findChildren($c, $level + 1);
		}
	}
}
findChildren('COM');
echo $part1 . "\n";


/* part 2 */
function findPath($p, $arr = []) {
	global $orbits2;
	if ($orbits2[$p]) {
		$p = $orbits2[$p];
		$arr[] = $p;
		return findPath($p, $arr);
	} else {
		$arr[] = $p;
		return $arr;
	}
}

[$arr1, $arr2] = [findPath('SAN'), findPath('YOU')];
$part2 = -1;
for ($i = 0; $i < count($arr2); $i++) {
	$j = array_search($arr2[$i], $arr1);
	if ($j) {
		$part2 = $i + $j;
		break;
	}
}
echo $part2 . "\n";
