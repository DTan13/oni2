open Oni_Core;
open Oni_Core.Utility;
open Oni_Extensions;

open Oni_IntegrationTestLib;

SyntaxServerTest.run(
  ~name="SyntaxServerReadExceptionTest",
  ({syntaxClient, isConnected, hasExited, wait}) => {
  Oni_Syntax_Client.simulateReadException(syntaxClient);

  // Syntax server should exit with code 2
  wait(~name="Closed", () => hasExited() == Some(2));
});
