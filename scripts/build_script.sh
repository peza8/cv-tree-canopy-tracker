#! Bash 
main() {
  run_cmake=0
  if [[ $# -gt 0 ]]; then
    loadArgs "$@"
  fi
  if [ ! -d "build" ]; then
    mkdir build
  fi
  cd build

  if [ ! -f ./Makefile ]; then
    echo "ZENN BUILD: No Makefile, rerunning cmake"
    run_cmake=1
  fi
  if [[ run_cmake -eq 1 ]]; then 
    cmake ..
  fi

  make
}

loadArgs() {
  echo "AEROVIEW ONBOARD Build: Loading arguments"
  for i in "$@"; do
    case $i in
      # force cmake to run again
      -r|--remake)
        run_cmake=1
      ;;

      *)
        echo "Unknown argument supplied: ${i}"
      ;;
  esac
  done
}

main "$@"