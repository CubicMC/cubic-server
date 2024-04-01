{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";

    pre-commit-hooks = {
      url = "github:cachix/pre-commit-hooks.nix";
      inputs = {
        nixpkgs.follows = "nixpkgs";
        flake-utils.follows = "flake-utils";
      };
    };
  };

  outputs =
    { self
    , pre-commit-hooks
    , nixpkgs
    , flake-utils
    }:
    flake-utils.lib.eachSystem [ "x86_64-linux" ] (system:
    let
      pkgs = nixpkgs.legacyPackages.${system};
    in
    rec {
      formatter = pkgs.nixpkgs-fmt;

      checks.pre-commit-check = pre-commit-hooks.lib.${system}.run {
        src = ./.;
        hooks = {
          nixpkgs-fmt.enable = true;
          clang-format.enable = true;
          check-merge-conflicts.enable = true;
          check-shebang-scripts-are-executable.enable = true;
          check-added-large-files.enable = true;
        };
      };

      devShells.default = pkgs.mkShell {
        inherit (checks.pre-commit-check) shellHook;

        hardeningDisable = [ "all" ];
        packages = with pkgs; [
          gcc11
          python3Packages.compiledb
          xmake
          clang-tools
        ];
      };
    });
}
