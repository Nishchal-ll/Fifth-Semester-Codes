<?php
$file = fopen("file.txt", "w");

if (!$file) {
    die("Failed to open file.");
}

fwrite($file, "Name: Nishchal\nRoll Number: 23081039");
fclose($file);

echo "File written successfully.";


// sudo chmod -R 777 /opt/lampp/htdocs/nishchal for file permissions

$file = fopen("file.txt", "r");
if (!$file) {
    die("Failed to open file.");
}
$content = fread($file, filesize("file.txt"));
fclose($file);

echo "<h3>File Content:</h3>";
echo nl2br($content);

echo"<br><br>";

$file = fopen("file.txt", "a");
if (!$file) {
    die("Failed to open file for appending.");
}
fwrite($file, "\nDate: " . date("Y-m-d"));
fclose($file);

echo "Current date added to file.";

echo"<br><br>";

if (rename("file.txt", "test.txt")) {
    echo "File renamed successfully to test.txt";
} else {
    echo "Failed to rename the file.";
}


?>
