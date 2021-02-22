docker run --entrypoint bash -it --rm --name ubi -v $(pwd):/root/aegi aegisub -c "
cd /root/aegi
bash -l
"
