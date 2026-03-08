#!/usr/bin/env bash
set -euo pipefail

REPO="ewhanhan/voyager-qmk"

echo "Triggering workflow..."
gh workflow run "Fetch and build layout" -R "$REPO"

# Poll until the triggered run appears
for _ in {1..10}; do
  sleep 2
  RUN_ID=$(gh run list -R "$REPO" -w "Fetch and build layout" -L1 --json databaseId,status -q '.[] | select(.status != "completed") | .databaseId')
  [[ -n "$RUN_ID" ]] && break
done

if [[ -z "$RUN_ID" ]]; then
  echo "Error: workflow run not found" >&2
  exit 1
fi
echo "Watching run $RUN_ID..."
gh run watch "$RUN_ID" -R "$REPO" --exit-status

echo "Pulling latest changes..."
git pull

echo "Done."
