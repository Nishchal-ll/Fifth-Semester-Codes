<?php
// Start the session
session_start();

// Verify if the session variables are set
if (isset($_SESSION["user"]) && isset($_SESSION["email"])) {
    echo "User: " . $_SESSION["user"] . "<br>";
    echo "Email: " . $_SESSION["email"] . "<br>";
} else {
    echo "No session found. Please start a session first.<br>";
}
echo "Click <a href='sessionend.php'>here</a> to destroy the session.<br>";
?>
