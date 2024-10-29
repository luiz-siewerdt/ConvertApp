#!/bin/bash

arg=$1

script_path="$(dirname "$(realpath "$0")")"

if ! cd "$script_path/build"; then
	mkdir -p "$script_path/build" && cd "$script_path/build" || exit
fi

SESSION_NAME_APP="convert_app_session"

run_app() {
	if tmux has-session -t $SESSION_NAME_APP 2>/dev/null; then
		tmux kill-session -t $SESSION_NAME_APP
		sleep 1
	fi

	cmake .. && make

	tmux new-session -d -s $SESSION_NAME_APP "bash -c './ConvertApp $arg; echo \"Program ended. press any key to exit\"; read '"
}

run_app

while inotifywait -r -e modify ../src ../include ../CMakeLists.txt; do
	run_app
done
