echo "you can input exit to abort git push."
$commit_info=Read-Host -Prompt "input commit info"
if($commit_info -eq "exit"){
    echo "git push exit!"
}else{
    git add include/*
    git add src/*
    git add tests/*
    git add res/*
    git add docs/*
    git add license/*
    git add CMakeLists.txt
    git add README.md
    git add .gitignore
    git add git-push.ps1
    git add git-keep.ps1
    git add build*.ps1
    git add clean.ps1
    git add run.ps1
    git commit -m $commit_info
    git push
}
