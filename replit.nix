{ pkgs }: {
	deps = [
		pkgs.cliquer
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
    pkgs.ncurses
	];
}