#!/bin/bash

SESSION_NAME_APP="convert_app_session"
SESSION_NAME_KILL="convert_app_kill"

if tmux has-session -t $SESSION_NAME_KILL 2>/dev/null; then
	tmux kill-session -t $SESSION_NAME_KILL
fi

tmux new-session -d -s $SESSION_NAME_KILL "./watch_files.sh $1"

while true; do
	sleep 0.5
	if tmux has-session -t $SESSION_NAME_APP 2>/dev/null; then
		tmux attach -t $SESSION_NAME_APP
	fi
done
