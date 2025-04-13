<?php
// Start the session
session_start();

// Set session variables
$_SESSION["user"] = "JohnDoe";
$_SESSION["email"] = "johndoe@example.com";

echo "Session has been started. User and email have been set.<br>";
echo "Click <a href='sessionverify.php'>here</a> to verify the session.<br>";
?>
